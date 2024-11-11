#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;
int n, k;
void solve() {
  scanf("%d%d", &n, &k);
  if (k == 1 || k > 3) {
    puts("-1");
    return;
  }
  vector<pair<int, int> > ans;
  if (k == 2) {
    if (n <= 4) {
      puts("-1");
      return;
    }
    for (int i = (1); i < (n); ++i) ans.push_back(make_pair(i, i + 1));
  } else if (k == 3) {
    if (n <= 3) {
      puts("-1");
      return;
    }
    ans.push_back(make_pair(1, 2));
    ans.push_back(make_pair(2, 3));
    ans.push_back(make_pair(3, 4));
    for (int i = (5); i < (n + 1); ++i) {
      ans.push_back(make_pair(1, i));
      ans.push_back(make_pair(3, i));
    }
  }
  printf("%d\n", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  solve();
  return 0;
}
