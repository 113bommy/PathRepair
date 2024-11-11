#include <bits/stdc++.h>
using namespace std;
void readInputData();
void run();
int main(int argc, char** argv) {
  ios_base::sync_with_stdio(false);
  readInputData();
  run();
  return 0;
}
int n;
int m;
void readInputData() { cin >> n >> m; }
void run() {
  long long s;
  long long f;
  long long t;
  long long k;
  long long a;
  long long b;
  for (int i = 0; i < n; ++i) {
    cin >> s >> f >> t;
    if (s == f) {
      cout << t << endl;
    } else if (s < f) {
      a = t - (s - 1);
      b = 2 * (m - 1);
      k = (a + b - 1) / b;
      cout << (s - 1) + 2 * (m - 1) * k + (f - s) << endl;
    } else {
      a = t - 2 * (m - 1) + (s - 1);
      b = 2 * (m - 1);
      k = (a + b - 1) / b;
      cout << 2 * (m - 1) - (s - 1) + 2 * (m - 1) * k + (s - f) << endl;
    }
  }
}
