#include <bits/stdc++.h>
using namespace std;
const char IN[] = "_.in";
const char OUT[] = "_.out";
const int maxn = 200000;
int ntest = 0, test;
int n;
int fx[60][60][60][60];
int a[60], b[60];
bool ok(int i, int j) { return (a[i] == a[j] || b[i] == b[j]); }
bool dp(int i, int a, int b, int now) {
  if (fx[i][a][b][now] != -1) return fx[i][a][b][now];
  if (i == 3)
    if (ok(now, a) && ok(now, b)) {
      fx[3][a][b][now] = 1;
      return 1;
    }
  if (ok(now, a))
    if (dp(i - 1, b, i - 3, now)) return (fx[i][a][b][now] = 1);
  if (ok(now, i - 3))
    if (dp(i - 1, b, now, a)) return (fx[i][a][b][now] = 1);
  fx[i][a][b][now] = 0;
  return 0;
}
void solve() {
  cin >> n;
  char c;
  for (int i = (1); i <= (n); i++) {
    cin >> c;
    a[i] = c;
    cin >> c;
    b[i] = c;
  }
  memset((fx), (-1), sizeof(fx));
  if (n == 1 || dp(n, n - 1, n - 2, n))
    cout << "YES";
  else
    cout << "NO";
}
int main() {
  solve();
  return 0;
}
