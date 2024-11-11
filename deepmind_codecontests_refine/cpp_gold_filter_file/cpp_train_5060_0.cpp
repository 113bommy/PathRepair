#include <bits/stdc++.h>
using namespace std;
long long a[4000];
long long b[4000];
long long sum[4000];
set<long long> s;
set<long long> ans;
set<long long> st;
int main() {
  int n, k;
  memset(sum, 0, sizeof(sum));
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= k; i++) {
    scanf("%lld", &b[i]);
    s.insert(b[i]);
  }
  for (int i = 1; i <= n; i++) {
    long long t = b[1];
    st.clear();
    st.insert(b[1]);
    for (int j = 2; j <= i; j++) {
      auto it = s.find(t - (sum[i] - sum[j - 1]));
      if (it == s.end()) continue;
      st.insert(*it);
    }
    for (int j = i + 1; j <= n; j++) {
      long long ttt = t + sum[j] - sum[i];
      auto it = s.find(t + sum[j] - sum[i]);
      if (it == s.end()) continue;
      st.insert(*it);
    }
    if (st.size() == k) ans.insert(b[1] - sum[i]);
  }
  printf("%d", ans.size());
  return 0;
}
