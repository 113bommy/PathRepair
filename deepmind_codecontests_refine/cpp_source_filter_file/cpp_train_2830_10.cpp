#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
pair<int, int> a[N];
int b[N];
int c[N];
int n, m;
int r;
void enter() {
  int leng;
  string A;
  string B;
  cin >> leng >> A >> B;
  A = ' ' + A;
  B = ' ' + B;
  for (int i = 1; i <= leng; i++) {
    if (A[i] == 'a' && B[i] == 'b')
      b[++n] = i;
    else if (A[i] == 'b' && B[i] == 'a')
      c[++m] = i;
  }
}
void solve() {
  if ((n + m) % 2 != 0)
    cout << -1;
  else {
    for (int i = 1; i <= n; i += 2)
      if (i == n)
        continue;
      else {
        r++;
        a[r].first = b[i];
        a[r].second = b[i + 1];
      }
    for (int i = 1; i <= m; i += 2)
      if (i == n)
        continue;
      else {
        r++;
        a[r].first = c[i];
        a[r].second = c[i + 1];
      }
    if (n % 2 == 1) {
      r++;
      a[r].first = c[n];
      a[r].second = c[n];
      r++;
      a[r].first = c[n];
      a[r].second = b[n];
    }
    cout << r << endl;
    for (int i = 1; i <= r; i++)
      cout << a[i].first << ' ' << a[i].second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  enter();
  solve();
  return 0;
}
