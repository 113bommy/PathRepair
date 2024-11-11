#include <bits/stdc++.h>
inline long long rd() {
  long long _x = 0;
  int _ch = getchar(), _f = 1;
  for (; !isdigit(_ch) && (_ch != '-') && (_ch != EOF); _ch = getchar())
    ;
  if (_ch == '-') {
    _f = 0;
    _ch = getchar();
  }
  for (; isdigit(_ch); _ch = getchar()) _x = _x * 10 + _ch - '0';
  return _f ? _x : -_x;
}
void write(long long _x) {
  if (_x >= 10)
    write(_x / 10), putchar(_x % 10 + '0');
  else
    putchar(_x + '0');
}
inline void wrt(long long _x, char _p) {
  if (_x < 0) putchar('-'), _x = -_x;
  write(_x);
  if (_p) putchar(_p);
}
struct hashmp {
  int hd[30000001];
  int nx[5000005];
  long long val1[5000005];
  int val2[5000005];
  int cnt;
  int query(long long x) {
    int v = x % 30000001;
    for (int i = hd[v]; i; i = nx[i]) {
      if (val1[i] == x) return val2[i];
    }
    return -1;
  }
  int insert(long long x, int a) {
    int v = x % 30000001;
    nx[++cnt] = hd[v];
    hd[v] = cnt;
    val1[cnt] = x;
    val2[cnt] = a;
    return a;
  }
} mp;
char s[100005];
int n, m;
int S[26][100005], mx[26];
int pos[26][100005], idx[26][100005], la[26], total[26];
inline long long id(int x, int y) { return 1ll * x * (n + 1) + y; }
int C1, C2;
int DP(int l, int r) {
  C1++;
  if (l > r) return 0;
  int v = mp.query(id(l, r));
  if (v != -1) return v;
  C2++;
  unsigned int vis = 0;
  for (int i = 0; i < 26; i++) {
    int L = pos[i][l - 1] + 1, R = pos[i][r];
    if (L > R) continue;
    while (mx[i] < R) {
      mx[i]++;
      S[i][mx[i]] =
          S[i][mx[i] - 1] ^ DP(idx[i][mx[i] - 1] + 1, idx[i][mx[i]] - 1);
    }
    int res = S[i][R] ^ S[i][L];
    res ^= DP(l, idx[i][L] - 1) ^ DP(idx[i][R] + 1, r);
    vis |= 1 << res;
  }
  return mp.insert(id(l, r), __builtin_ctz(~vis) + 1);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    int x = s[i] - 'a';
    total[x]++, la[x] = i;
    pos[x][i] = total[x];
    idx[x][total[x]] = i;
    for (int j = 0; j < 26; j++) {
      pos[j][i] = pos[j][la[j]];
    }
  }
  m = rd();
  for (int i = 1; i <= m; i++) {
    int l = rd(), r = rd();
    bool flag = DP(l, r);
    if (flag)
      printf("Alice\n");
    else
      printf("Bob\n");
  }
}
