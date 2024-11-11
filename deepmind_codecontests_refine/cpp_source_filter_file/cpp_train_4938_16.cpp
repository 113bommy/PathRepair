#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
struct node {
  int id, p;
  bool operator<(const node& r) const { return p > r.p; }
} a[MAXN], b[MAXN];
int main() {
  long long n, v;
  scanf("%lld%lld", &n, &v);
  int cnt1 = 0, cnt2 = 0, x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x, &y);
    if (x == 1)
      a[cnt1].id = i, a[cnt1++].p = y;
    else
      b[cnt2].id = i, b[cnt2++].p = y;
  }
  sort(a, a + cnt1);
  sort(b, b + cnt2);
  int cur1 = 0, cur2 = 0, cap = v;
  long long res = 0;
  set<int> st;
  while (cur2 < cnt2 && cap >= 2) {
    res += b[cur2].p;
    st.insert(b[cur2].id);
    cap -= 2;
    cur2++;
  }
  while (cur1 < cnt1 && cap >= 1) {
    res += a[cur1].p;
    st.insert(a[cur1].id);
    cap -= 1;
    cur1++;
  }
  cur2--;
  while (cur1 < cnt1 && cur2 >= 0) {
    if (cur1 == cnt1 - 1) {
      if (a[cur1].p > b[cur2].p) {
        st.erase(b[cur2].id);
        st.insert(a[cur1].id);
        res += (a[cur1].p - b[cur2].p);
      }
      break;
    }
    if (a[cur1].p + a[cur1 + 1].p > b[cur2].p) {
      st.erase(b[cur2].id);
      st.insert(a[cur1].id);
      st.insert(a[cur1 + 1].id);
      res += (a[cur1].p + a[cur1].p - b[cur2].p);
      cur1 += 2;
      cur2--;
    } else
      break;
  }
  printf("%lld\n", res);
  for (auto it = st.begin(); it != st.end(); ++it) {
    printf("%d", *it);
  }
  puts("");
  return 0;
}
