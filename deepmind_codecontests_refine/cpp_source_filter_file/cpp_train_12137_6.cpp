#include <bits/stdc++.h>
const int N = 100010;
using namespace std;
bool vis[N];
struct NODE {
  int val, num;
} a[N];
bool cmp(NODE a, NODE b) { return a.val > b.val; }
vector<pair<int, int> > ans;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].val);
    a[i].num = i;
  }
  sort(a + 2, a + 1 + n, cmp);
  vis[1] = 1;
  int tmp = 1;
  for (int i = 2; i <= n; i++) {
    while (a[tmp].val == 0 && tmp < i) {
      tmp++;
    }
    if (tmp == i) {
      printf("-1\n");
      return 0;
    }
    ans.push_back(make_pair(tmp, a[i].num));
    a[tmp].val--;
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
