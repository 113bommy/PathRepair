#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 100;
int l[MAXN], r[MAXN];
vector<int> v;
struct cmp {
  bool operator()(int a, int b) {
    if (r[a] == r[b]) return l[a] > l[b];
    return r[a] < r[b];
  }
};
bool cmpv(int a, int b) { return l[a] < l[b]; }
multiset<int, cmp> st;
int main() {
#pragma warning(disable : 4996)
  int n, k, ans = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    v.push_back(i);
  }
  sort(v.begin(), v.end(), cmpv);
  for (int i = 0; i < n; i++) {
    st.insert(i);
    if (st.size() > k) st.erase(st.begin());
    if (st.size() == k) ans = max(ans, r[*st.begin()] - l[v[i]] + 1);
  }
  printf("%d\n", ans);
  st.clear();
  for (int i = 0; i < n; i++) {
    st.insert(v[i]);
    if (st.size() > k) st.erase(st.begin());
    if (st.size() == k && r[*st.begin()] - l[v[i]] + 1 == ans) {
      for (auto j : st) printf("%d ", j + 1);
      return 0;
    }
  }
  if (ans == 0) {
    for (int i = 1; i <= k; i++) printf("%d ", i);
  }
  return 0;
}
