#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 100 * 1000;
const int maxs = 10 * 1000;
const double epsilon = 1e-6;
int n;
int S[maxn];
int R[maxn];
int rMax[maxs + 1];
double value[maxs + 1];
bool winner[maxs + 1];
void read();
void initialize();
bool equal(double, double);
void debug();
int main() {
  read();
  initialize();
  for (int i = 1; i <= maxs; i++) {
    if (rMax[i] == 0) continue;
    bool bad = false;
    int minimum, maximum;
    double minValue, maxValue;
    minValue = 1e12 + 100;
    maxValue = -1;
    for (int j = 1; j <= maxs; j++) {
      if (j < i) {
        if (rMax[j] > rMax[i]) {
          double d =
              value[j] * value[i] * double(rMax[j] - rMax[i]) / double(i - j);
          maxValue = max(maxValue, d);
        }
      }
      if (j > i) {
        if (rMax[i] < rMax[j] || equal(rMax[i], rMax[j])) {
          bad = true;
          break;
        }
        double d =
            (value[j] * value[i]) * double(rMax[i] - rMax[j]) / double(j - i);
        minValue = max(minValue, d);
      }
    }
    if (bad)
      winner[i] = false;
    else if (minimum - (1e12) > 0 || maximum < 0 || maxValue < minValue ||
             equal(maxValue, minValue))
      winner[i] = true;
    else
      winner[i] = false;
  }
  bool first = true;
  for (int i = 0; i < n; i++) {
    if (R[i] == rMax[S[i]] && winner[S[i]]) {
      if (first) {
        cout << i + 1;
        first = false;
      } else
        cout << ' ' << i + 1;
    }
  }
  cout << endl;
  return 0;
}
void read() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> S[i] >> R[i];
}
void initialize() {
  for (int i = 0; i < n; i++) rMax[S[i]] = max(rMax[S[i]], R[i]);
  for (int i = 1; i <= maxs; i++) value[i] = double(i) / double(rMax[i]);
}
bool equal(double a, double b) {
  if (abs(a - b) < epsilon) return true;
  return false;
}
void debug() {
  for (int i = 1; i <= maxs; i++)
    if (rMax[i] > 0)
      cout << "Maximum r of part number " << i << " equals: " << rMax[i]
           << endl;
  for (int i = 1; i <= maxs; i++)
    if (rMax[i] > 0)
      cout << "Value of part number " << i << " equals: " << value[i] << endl;
}
