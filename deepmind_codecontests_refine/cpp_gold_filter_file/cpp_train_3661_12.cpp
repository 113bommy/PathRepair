#include <bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 1e5 + 5;
long long a[maxn];
vector<pair<int, int> > ans;
deque<long long> de;
long long m;
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    de.push_back(a[i]);
  }
  long long maxx = *max_element(a + 1, a + n + 1);
  while (de.front() < maxx) {
    ans.push_back({de[0], de[1]});
    {
      if (de[0] > de[1]) {
        long long tmp = de[0];
        de.pop_front();
        de.push_back(de[0]);
        de[0] = tmp;
      } else {
        de.push_back(de[0]);
        de.pop_front();
      }
    }
  }
  while (q--) {
    scanf("%lld", &m);
    if (m <= ans.size())
      printf("%d %d\n", ans[m - 1].first, ans[m - 1].second);
    else {
      printf("%lld %lld\n", maxx, de[(m - ans.size() - 1) % (n - 1) + 1]);
    }
  }
  return 0;
}
