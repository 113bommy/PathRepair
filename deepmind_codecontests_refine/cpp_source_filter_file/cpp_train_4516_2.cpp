#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void checkMax(T& a, const T& b) {
  if (a < b) a = b;
}
template <typename T>
inline void checkMin(T& a, const T& b) {
  if (a > b) a = b;
}
int m, n;
int min_q;
vector<int> a;
int main() {
  int q;
  scanf("%d", &m);
  min_q = 10001;
  for (int n___LINE__ = (m), i = 0; i < n___LINE__; ++i) {
    scanf("%d", &q);
    checkMin(min_q, q);
  }
  scanf("%d", &n);
  for (int n___LINE__ = (n), i = 0; i < n___LINE__; ++i) {
    scanf("%d", &q);
    a.push_back(q);
  }
  sort((a).begin(), (a).end());
  int ans = 0;
  for (int i = n; i >= 1; i -= min_q + 2) {
    ans += accumulate(a.begin() + max(0, i - min_q), a.begin() + i, 0);
  }
  printf("%d\n", ans);
  return 0;
}
