#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void input(T &x) {
  register char c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
const int N = 1e5 + 5;
string s;
int n;
int B[11][11][4][N];
int Pos[N][11];
void upd(int L, int idx, int id, int x, int v) {
  x++;
  while (x < N) B[L][idx][id][x] += v, x += x & -x;
}
int query(int L, int idx, int id, int x) {
  int res = 0;
  x++;
  while (x > 0) res += B[L][idx][id][x], x -= x & -x;
  return res;
}
int m[128];
char inp[1200];
int main() {
  m['A'] = 0, m['T'] = 1, m['G'] = 2, m['C'] = 3;
  cin >> s;
  n = s.length();
  for (int L = 1; L <= 10; L++) {
    for (int i = 0; i < L; i++) {
      int start = i;
      for (int j = start; j < n; j += L) {
        Pos[j][L] = i;
        upd(L, i, m[s[j]], j, 1);
      }
    }
  }
  int q, type, u, v;
  input(q);
  while (q--) {
    input(type);
    if (type == 2) {
      input(u), input(v);
      u--, v--;
      scanf("%s", inp);
      int nl = strlen(inp);
      long long ans = 0;
      for (int i = 0; i < nl; i++) {
        int now = u + i;
        if (now > v) break;
        ans += query(nl, Pos[now][nl], m[inp[i]], v) -
               query(nl, Pos[now][nl], m[inp[i]], now - 1);
      }
      printf("%lld\n", ans);
    } else {
      input(u);
      u--;
      scanf(" %s ", inp);
      char now = inp[0];
      for (int L = 1; L <= 10; L++) {
        int idx = Pos[u][L];
        upd(L, idx, m[s[u]], u, -1);
        upd(L, idx, m[now], u, 1);
      }
      s[u] = now;
    }
  }
  return 0;
}
