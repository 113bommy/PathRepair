#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
template <int mod, int base>
class String_Hasher {
 public:
  int p[maxn], h[maxn];
  inline void init(int *s, int n) {
    for (int i = p[0] = 1; i <= n; i++) p[i] = 1ll * p[i - 1] * base % mod;
    for (int i = 1; i <= n; i++) h[i] = (1ll * h[i - 1] * base + s[i]) % mod;
  }
  inline int query(int l, int r) {
    return (h[r] - 1ll * h[l - 1] * p[r - l + 1] % mod + mod) % mod;
  }
  inline int query1(int l, int r, bool prev, bool nxtv) {
    int ans = query(l, r);
    if (prev) ans = (ans + p[r - l + 1]) % mod;
    if (nxtv) ans = (1ll * ans * base + 1) % mod;
    return ans;
  }
};
struct Hasher {
  String_Hasher<1000000009, 13131> H1;
  String_Hasher<1000000007, 13131> H2;
  inline void init(int *s, int n) {
    H1.init(s, n);
    H2.init(s, n);
  }
  inline pair<int, int> query(int l, int r) {
    return make_pair(H1.query(l, r), H2.query(l, r));
  }
  inline pair<int, int> query1(int l, int r, bool prev, bool nxtv) {
    return make_pair(H1.query1(l, r, prev, nxtv), H2.query1(l, r, prev, nxtv));
  }
} H;
char s[maxn];
int st[maxn], v[maxn], tot, n, q, sumv[maxn], rpos[maxn], lpos[maxn];
inline pair<int, int> query(int l, int r) {
  if (rpos[l] == rpos[r]) return make_pair((r - l + 1) & 1, (r - l + 1) & 1);
  bool flagl, flagr, posl, posr;
  if (s[l] == '0')
    posl = st[l], flagl = 0;
  else {
    posl = st[rpos[l] + 1];
    flagl = (rpos[l] - l + 1) & 1;
  }
  if (s[r] == '0')
    posr = st[r], flagr = 0;
  else {
    posr = st[lpos[r] - 1];
    flagr = (r - lpos[r] + 1) & 1;
  }
  return H.query1(posl, posr, flagl, flagr);
}
int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 1; i <= n; i++) sumv[i] = sumv[i - 1] + s[i] - '0';
  for (int i = n; i; i--)
    if (s[i] == '1')
      rpos[i] = s[i + 1] == '1' ? rpos[i + 1] : i;
    else
      rpos[i] = i;
  for (int i = 1; i <= n; i++)
    if (s[i] == '1')
      lpos[i] = s[i - 1] == '1' ? lpos[i - 1] : i;
    else
      lpos[i] = i;
  for (int i = 1; i <= n;) {
    if (s[i] == '1' && s[i + 1] == '1') {
      i += 2;
      continue;
    }
    v[++tot] = s[i] - '0';
    st[i] = tot;
    i++;
  }
  H.init(v, tot);
  scanf("%d", &q);
  while (q--) {
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    if (sumv[a + l - 1] - sumv[a - 1] != sumv[b + l - 1] - sumv[b - 1]) {
      puts("No");
      continue;
    }
    if (query(a, a + l - 1) == query(b, b + l - 1))
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
