#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct node {
  int val, idx;
};
node a[N], b[N];
bool cmp(node x, node y) { return x.val > y.val; }
int main() {
  int n;
  vector<int> yy;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].val);
    a[i].idx = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i].val);
    b[i].idx = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  yy.push_back(a[1].idx);
  for (int i = 3; i <= n; i += 2) {
    if (b[a[i].idx].val > b[a[i + 1].idx].val)
      yy.push_back(a[i].idx);
    else
      yy.push_back(a[i - 1].idx);
  }
  if ((n & 1) == 0) yy.push_back(a[n].idx);
  cout << yy.size() << endl;
  for (int i = 0; i < yy.size(); ++i) cout << yy[i] << " ";
  return 0;
}
