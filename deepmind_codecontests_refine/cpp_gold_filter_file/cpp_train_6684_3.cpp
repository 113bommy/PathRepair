#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 998244353;
inline int mul(int a, int b) { return 1LL * a * b % mod; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a < b ? a - b + mod : a - b; }
int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}
inline int rev(int x) { return qpow(x, mod - 2); }
int p[maxn], sum[maxn];
set<int> st;
int ans = 0;
int cal(int l, int r) { return mul(sub(sum[r], sum[l - 1]), rev(p[r])); }
void solve(int x) {
  auto it = st.find(x);
  if (it != st.end()) {
    int l1 = *(--st.find(x)), l2 = *(++st.find(x));
    st.erase(x);
    ans = sub(ans, add(cal(l1, x - 1), cal(x, l2 - 1)));
    ans = add(ans, cal(l1, l2 - 1));
  } else {
    st.insert(x);
    int l1 = *(--st.find(x)), l2 = *(++st.find(x));
    ans = sub(ans, cal(l1, l2 - 1));
    ans = add(ans, add(cal(l1, x - 1), cal(x, l2 - 1)));
  }
}
int main() {
  int n, q;
  cin >> n >> q;
  p[0] = 1, sum[0] = 0;
  int fm = rev(100);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    sum[i] = add(sum[i - 1], p[i - 1]);
    p[i] = mul(p[i - 1], mul(x, fm));
  }
  st.insert(1), st.insert(n + 1);
  ans = cal(1, n);
  while (q--) {
    int x;
    scanf("%d", &x);
    solve(x);
    printf("%d\n", ans);
  }
}
