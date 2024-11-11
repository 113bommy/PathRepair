#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000;
long long p[MAXN + 10], v[MAXN + 10], d[MAXN + 10];
bool lft[MAXN + 10];
int n;
void print(int n) {
  for (int i = 0; i < n; i++) cout << p[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << lft[i] << " ";
  cout << endl;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i] >> d[i] >> p[i];
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (lft[i]) continue;
    res++;
    long long f = 0, effect = 0;
    for (int j = i + 1; j < n; j++) {
      if (lft[j]) continue;
      p[j] -= max(0ll, v[i] - f++);
      p[j] -= effect;
      if (p[j] < 0) {
        lft[j] = true;
        effect += d[j];
      }
    }
  }
  cout << res << endl;
  for (int i = 0; i < n; i++)
    if (!lft[i]) cout << i + 1 << " ";
  cout << endl;
}
