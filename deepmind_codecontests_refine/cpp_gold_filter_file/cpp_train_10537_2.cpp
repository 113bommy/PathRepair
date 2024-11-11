#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  x = 0;
  bool f = 0;
  char ch = (char)getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = (char)getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch & 15);
    ch = (char)getchar();
  }
  if (f) x = -x;
}
template <typename T>
inline void write(T x) {
  static int st[35];
  int top = 0;
  do {
    st[top++] = x % 10;
    x /= 10;
  } while (x);
  while (top) putchar(st[--top] + '0');
}
const double pi = acos(-1.0);
const double eps = (double)1e-4;
const int mod = 10007;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 10;
int cnts[26], cntt[26];
int nxt[maxn][26];
int n, m;
void debug() {
  for (int i = 0; i < m; i++) {
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    n = s.size();
    m = t.size();
    fill(cnts, cnts + 26, 0);
    fill(cntt, cntt + 26, 0);
    int ans = 0;
    int i = 0, j = 0;
    for (i = 0; i < n; i++) cnts[s[i] - 'a']++;
    for (i = 0; i < m; i++) cntt[t[i] - 'a']++;
    for (i = 0; i < 26; i++) {
      if (cntt[i] && (!cnts[i])) {
        ans = -1;
        goto done;
      }
    }
    for (i = 0; i <= n + 2; i++) {
      for (j = 0; j < 26; j++) nxt[i][j] = 1e9;
    }
    for (i = n - 1; i >= 0; i--) {
      for (j = 0; j < 26; j++) {
        nxt[i][j] = nxt[i + 1][j];
      }
      int cur = s[i] - 'a';
      nxt[i][cur] = ((nxt[i][cur] < i) ? (nxt[i][cur]) : (i));
    }
    i = 0, j = 0;
    while (j < m) {
    itr:
      ans++;
      i = 0;
      while (1) {
        int cur = t[j] - 'a';
        int nxtidx = nxt[i][cur];
        if (nxtidx == 1e9) {
          goto itr;
        }
        j++;
        i = nxtidx + 1;
        if (j == m) goto done;
      }
    }
  done:
    cout << ans << endl;
  }
}
