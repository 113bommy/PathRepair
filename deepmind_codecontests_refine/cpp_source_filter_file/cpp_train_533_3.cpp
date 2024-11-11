#include <bits/stdc++.h>
using namespace std;
int arr[300001], idx[150002];
vector<pair<int, int> > ans;
int main() {
  int n, qks;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    idx[arr[i]] = i;
  }
  qks = n / 2;
  for (int i = n / 2 + 1; i <= n; i++) {
    if (arr[i] == i) continue;
    int ii = idx[i];
    if (ii <= qks) {
      ans.push_back({ii, n});
      swap(arr[ii], arr[n]);
      idx[arr[ii]] = ii;
      idx[arr[n]] = n;
      ans.push_back({1, n});
      swap(arr[1], arr[n]);
      idx[arr[1]] = 1;
      idx[arr[n]] = n;
    } else {
      ans.push_back({1, ii});
      swap(arr[1], arr[ii]);
      idx[arr[1]] = 1;
      idx[arr[ii]] = ii;
    }
    ans.push_back({1, i});
    swap(arr[1], arr[i]);
    idx[arr[1]] = 1;
    idx[arr[i]] = i;
  }
  for (int i = 1; i <= qks; i++) {
    if (arr[i] == i) continue;
    int ii = idx[i];
    if (ii != n) {
      ans.push_back({ii, n});
      swap(arr[ii], arr[n]);
      idx[arr[ii]] = ii;
      idx[arr[n]] = n;
    }
    ans.push_back({n, i});
    swap(arr[n], arr[i]);
    idx[arr[n]] = n;
    idx[arr[i]] = i;
  }
  printf("%d\n", ans.size());
  for (pair<int, int> v : ans) printf("%d %d\n", v.first, v.second);
  return 0;
}
