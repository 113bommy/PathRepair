#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
int n;
int a[maxn];
vector<int> ans, st;
map<int, int> cnt, cov;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if (cnt[x] == 3) {
      cov[x] = x;
    }
    if (cov[x]) {
      ans.push_back(cov[x]);
      ans.push_back(x);
      ans.push_back(cov[x]);
      ans.push_back(x);
      cov.clear();
      cnt.clear();
      st.clear();
      continue;
    }
    while (st.size() && cnt[x] >= 1 && st.back() != x) {
      cov[st.back()] = x;
      cnt[st.back()]--;
      st.pop_back();
    }
    cnt[x]++;
    st.push_back(x);
  }
  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
