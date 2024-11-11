#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long input() {
  long long n;
  cin >> n;
  return n;
}
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const int MAXN = 1e6 + 10;
const int MAXLG = 18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 8e18;
long long m;
string t[110];
string s, sr;
long long f[1010][26];
long long pi[1010];
long long mx1[1010];
long long mx2[1010];
long long ans;
string rev(string a) {
  string tmp;
  for (int i = 0; i < a.size(); i++) tmp = a[i] + tmp;
  return tmp;
}
void solve(string a) {
  if (a.size() == 1) return;
  memset(mx1, 0, sizeof(mx1));
  memset(mx2, 0, sizeof(mx2));
  memset(pi, 0, sizeof(pi));
  memset(f, 0, sizeof(f));
  int n = a.size();
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j and a[i] != a[j]) j = pi[j - 1];
    if (a[i] == a[j]) j++;
    pi[i] = j;
  }
  a += "#";
  n++;
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      int j = i;
      if (i and c != a[i] - 'A')
        f[i][c] = f[pi[i - 1]][c];
      else
        f[i][c] = i + (c == a[i] - 'A');
    }
  }
  long long k = 0;
  for (int i = 0; i < s.size(); i++) {
    k = f[k][s[i] - 'A'];
    mx1[i] = max(k, mx1[i - 1]);
  }
  n--;
  memset(pi, 0, sizeof(pi));
  memset(f, 0, sizeof(f));
  a = a.substr(0, n);
  a = rev(a);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j and a[i] != a[j]) j = pi[j - 1];
    if (a[i] == a[j]) j++;
    pi[i] = j;
  }
  a += "#";
  n++;
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      int j = i;
      if (i and c != a[i] - 'A')
        f[i][c] = f[pi[i - 1]][c];
      else
        f[i][c] = i + (c == a[i] - 'A');
    }
  }
  k = 0;
  for (int i = 0; i < sr.size(); i++) {
    k = f[k][sr[i] - 'A'];
    mx2[i] = max(k, mx2[i - 1]);
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (mx1[i] + mx2[s.size() - i - 2] >= n - 1) {
      ans++;
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> s;
  sr = rev(s);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> t[i];
    solve(t[i]);
  }
  cout << ans << "\n";
}
