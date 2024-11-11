#include <bits/stdc++.h>
using namespace std;
string s;
long long n;
long long p[50001][27];
long long a[27];
long long f[51][50001];
long long ans(0);
long long leng;
long long poi;
vector<char> St;
void Solve() {
  f[1][0] = p[n][s[0] - 'a'];
  leng = 0;
  poi = 0;
  for (int i = 1; i < n; i++) f[1][i] = max(f[1][i - 1], p[n][s[i] - 'a']);
  ans = 1;
  for (int k = 2; k <= min(50LL, n); k++) {
    f[k][0] = -1;
    for (int i = 1; i < n; i++) {
      f[k][i] = f[k][i - 1];
      if (f[k - 1][i - 1] >= 0)
        f[k][i] = max(f[k][i], p[f[k - 1][i - 1]][s[i] - 'a']);
      if (f[k][i] > i) {
        if (ans < k * 2) {
          leng = k;
          poi = i;
          ans = k * 2;
        }
      }
      if (f[k][i] == i) {
        if (ans < k * 2 - 1) {
          ans = k * 2 - 1;
          leng = k;
          poi = i;
        }
      }
    }
  }
  while (leng > 0 && poi >= 0) {
    if (s[poi] == s[f[leng][poi]]) {
      leng--;
      St.push_back(s[poi]);
    }
    poi--;
  }
  if (ans == 1) {
    cout << s[0];
    return;
  }
  if (ans % 2 == 0) {
    for (int i = St.size() - 1; i >= 0; i--) cout << St[i];
    for (int i = 0; i < St.size(); i++) cout << St[i];
  } else {
    for (int i = St.size() - 1; i > 0; i--) cout << St[i];
    for (int i = 0; i < St.size(); i++) cout << St[i];
  }
}
void Enter() {
  cin >> s;
  n = s.length();
  fill_n(&a[0], sizeof(a) / sizeof(a[0]), -1);
  for (int i = 0; i <= n; i++) {
    for (int k = 0; k < 27; k++) p[i][k] = a[k];
    if (i < n) a[s[i] - 'a'] = i;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Enter();
  Solve();
}
