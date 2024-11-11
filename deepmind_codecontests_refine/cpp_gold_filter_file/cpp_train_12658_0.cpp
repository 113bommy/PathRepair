#include <bits/stdc++.h>
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
using namespace std;
const long long MOD = 1e18;
long long n, k, a[400005];
set<pair<int, int> > st;
long long nxt[400005], pre[400005];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  fill(pre, pre + 400005 - 2, 400005 - 2);
  for (int i = n; i >= 1; i--) nxt[i] = pre[a[i]], pre[a[i]] = i;
  long long ans = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (st.find({i, a[i]}) == st.end()) {
      ans++;
      if (st.size() >= k) {
        set<pair<int, int> >::iterator it = st.end();
        it--;
        st.erase(it);
      }
    }
    st.erase({i, a[i]});
    st.insert({nxt[i], a[i]});
  }
  cout << ans;
}
