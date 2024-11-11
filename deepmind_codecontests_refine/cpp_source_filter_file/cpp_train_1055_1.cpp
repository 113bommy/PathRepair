#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int inf = 1LL << 32;
struct node {
  long long int b, l;
};
bool cmp(node a, node b) {
  if (a.b != b.b) return a.b > b.b;
  return a.l > b.l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  node a[n];
  for (int i = 0; i < n; ++i) cin >> a[i].l >> a[i].b;
  set<long long int> st;
  sort(a, a + n, cmp);
  long long int sum = 0, ans = -1;
  for (int i = 0; i < k; ++i) {
    st.insert(a[i].l);
    sum += a[i].l;
    ans = max(ans, sum * a[i].b);
  }
  for (int i = k; i < n; i++) {
    sum -= *st.begin();
    st.erase(st.begin());
    st.insert(a[i].l);
    sum += a[i].l;
    ans = max(ans, sum * a[i].b);
  }
  cout << ans;
}
