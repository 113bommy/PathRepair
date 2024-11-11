#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N], n;
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &n);
  register int i, j;
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (i = 1; i <= n - 2; ++i)
    if (a[i]) {
      for (j = 1; j <= (n - i >> 1); ++j)
        if (a[i + j]) break;
      if (j > (n - i >> 1)) j = 1;
      a[i] ^= 1, a[i + j] ^= 1, a[i + j + j] ^= 1,
          ans.push_back(make_pair(i, j));
    }
  for (i = n - 1; i <= n; ++i)
    if (a[i]) {
      if (i <= 6) return puts("NO"), 0;
      a[i] = 0, ans.push_back(make_pair(i - 6, 1)),
      ans.push_back(make_pair(i - 6, 3)), ans.push_back(make_pair(i - 5, 1));
    }
  puts("YES"), printf("%d\n", ans.size());
  for (const auto &i : ans)
    printf("%d %d %d\n", i.first, i.first + i.second,
           i.first + i.second + i.second);
  return 0;
}
