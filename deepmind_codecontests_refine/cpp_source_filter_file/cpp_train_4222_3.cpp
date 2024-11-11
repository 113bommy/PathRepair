#include <bits/stdc++.h>
using namespace std;
int LIS(vector<int> arr) {
  vector<int> dp;
  for (int i = 0; i < (int)(arr.size()); i++) {
    vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), arr[i]);
    if (it == dp.end())
      dp.push_back(arr[i]);
    else
      *it = arr[i];
  }
  return dp.size();
}
int x[1000000], y[1000000], tmp[1000000];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", x + i);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", y + i);
    tmp[y[i]] = n - i;
  }
  for (int i = 0; i < (int)(n); i++) x[i] = tmp[i + 1];
  printf("%d\n", LIS(vector<int>(x, x + n)));
  return 0;
}
