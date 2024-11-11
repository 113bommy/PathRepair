#include <bits/stdc++.h>
using namespace std;
const long long modn = 998244353;
long long powmod(long long a, long long p) {
  long long ans = 1;
  while (p) {
    if (p % 2) {
      ans *= a;
      ans %= modn;
    }
    p /= 2;
    a *= a;
    a %= modn;
  }
  return ans;
}
int arr[1001000];
int tr[400400 * 4][2];
void build(int o, int l, int r) {
  if (l == r) {
    tr[o][0] = 100 * powmod(arr[l], modn - 2) % modn;
    tr[o][1] = (100) * powmod(arr[l], modn - 2) % modn;
    return;
  }
  int mid = (l + r) / 2;
  build(o * 2 + 1, l, mid);
  build(o * 2 + 2, mid + 1, r);
  int oxl = o * 2 + 1;
  int oxr = o * 2 + 2;
  tr[o][0] = tr[oxl][0] * tr[oxr][1] + tr[oxr][0];
  tr[o][0] %= modn;
  tr[o][1] = tr[oxl][1] * tr[oxr][1] % modn;
}
struct pii {
  long long k, c;
};
pii query(int o, int L, int R, int l, int r) {
  if (l <= L && r >= R) {
    return pii{tr[o][1], tr[o][0]};
  }
  int mid = (L + R) / 2;
  if (l > mid) return query(o * 2 + 2, mid + 1, R, l, r);
  if (r <= mid) return query(o * 2 + 1, L, mid, l, r);
  pii ansl = query(o * 2 + 1, L, mid, l, r);
  pii ansr = query(o * 2 + 2, mid + 1, R, l, r);
  return pii{ansl.k * ansr.k % modn, (ansr.k * ansl.c % modn + ansr.c) % modn};
}
set<int> st;
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  build(0, 0, n - 1);
  st.insert(0);
  st.insert(n);
  long long ans = query(0, 0, n - 1, 0, n - 1).c;
  while (q--) {
    int t;
    scanf("%d", &t);
    t--;
    if (st.find(t) == st.end()) {
      auto it = st.lower_bound(t);
      int r = *it;
      it--;
      int l = *it;
      ans -= query(0, 0, n - 1, l, r - 1).c;
      ans += query(0, 0, n - 1, l, t - 1).c;
      ans += query(0, 0, n - 1, t, r - 1).c;
      st.insert(t);
    } else {
      st.erase(st.find(t));
      auto it = st.lower_bound(t);
      int r = *it;
      it--;
      int l = *it;
      ans += query(0, 0, n - 1, l, r - 1).c;
      ans -= query(0, 0, n - 1, l, t - 1).c;
      ans -= query(0, 0, n - 1, t, r - 1).c;
    }
    ans %= modn;
    ans += modn;
    ans %= modn;
    printf("%I64d\n", ans);
  }
  return 0;
}
