#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int n_ = 1e5 + 5;
int n;
long long a[n_], b[n_], dp[n_];
vector<int> st;
vector<long double> p;
long double getIntersect(int i, int j) {
  return (dp[j] - dp[i]) / (long double)(b[i] - b[j]);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  for (int i = 0; i < n; i++) scanf("%lld", b + i);
  dp[0] = b[0];
  st.push_back(0);
  p.push_back(2e9);
  int id;
  for (int i = 1; i < n; i++) {
    id = lower_bound(p.begin(), p.end(), (long double)a[i] - 1) - p.begin();
    dp[i] = dp[st[id]] + b[st[id]] * (a[i] - 1) + b[i];
    while (st.size() > 1 && getIntersect(st[st.size() - 2], st.back()) <
                                getIntersect(st.back(), i)) {
      st.pop_back();
      p.pop_back();
    }
    p.back() = getIntersect(st.back(), i);
    p.push_back(2e9);
    st.push_back(i);
  }
  printf("%lld", dp[n - 1]);
  return 0;
}
