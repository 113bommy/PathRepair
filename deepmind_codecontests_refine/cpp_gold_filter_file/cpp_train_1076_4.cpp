#include <bits/stdc++.h>
using namespace std;
int oo = (int)1e9;
map<int, vector<int> > m;
int mx[100000][10];
int nums[100000];
int ind[100000];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", &nums[i]);
    vector<int> &v = m[nums[i]];
    ind[i] = v.size();
    v.push_back(i);
  }
  for (int ir = n - 1; ir >= 0; ir--)
    for (int j = ind[ir] - 1; j >= 0; j--) {
      int il = m[nums[ir]][j];
      if (ir + 1 < n && il + 1 < n && nums[ir + 1] == nums[il + 1]) {
        mx[ir][j] = mx[ir + 1][ind[il + 1]] + 1;
        mx[il][ind[ir]] = mx[ir + 1][ind[il + 1]] + 1;
      }
    }
  vector<pair<int, int> > v;
  for (int il = 0; il < (int)(n); il++) {
    vector<int> &x = m[nums[il]];
    for (int j = 0; j < (int)(x.size()); j++)
      if (j > ind[il]) {
        int ir = x[j];
        int d = ir - il - 1;
        if (d <= mx[il][j]) v.push_back(make_pair(d, il));
      }
  }
  sort(v.begin(), v.end());
  int st = 0;
  for (int i = 0; i < (int)(v.size()); i++)
    if (v[i].second >= st) st = v[i].second + v[i].first + 1;
  printf("%d\n", n - st);
  for (int i = st; i < n; i++) {
    if (i != st) printf(" ");
    printf("%d", nums[i]);
  }
  printf("\n");
  return 0;
}
