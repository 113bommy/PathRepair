#include <bits/stdc++.h>
using namespace std;
int arr[300001];
map<int, int> mp1;
map<int, int> mp2;
vector<int> v;
long long sum[300001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    if (!mp1.count(arr[i])) mp1[arr[i]] = 0, mp2[arr[i]] = n + 1;
    mp1[arr[i]] = max(mp1[arr[i]], i + 1);
    mp2[arr[i]] = min(mp2[arr[i]], i + 1);
  }
  bool x = false;
  int t = -1e9;
  int start, end;
  start = end = 0;
  for (int i = 0; i < n; ++i) {
    if (mp1[arr[i]] != mp2[arr[i]]) {
      if (arr[i] >= t) {
        t = arr[i];
        start = mp2[arr[i]];
        end = mp1[arr[i]];
      }
      if (arr[i] >= 0) {
        x = true;
        break;
      }
    }
  }
  if (!x) {
    printf("%d %d\n", t * 2, n - 2);
    for (int i = 1; i <= n; ++i) {
      if (i != start && i != end) printf("%d ", i);
    }
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (arr[i] > 0)
      t = arr[i];
    else
      t = 0;
    sum[i + 1] = sum[i] + t;
  }
  long long ans = 0;
  int l, r;
  for (int i = 0; i < n; ++i) {
    l = mp2[arr[i]];
    r = mp1[arr[i]];
    if (l != r) {
      if (arr[i] < 0)
        t = arr[i] * 2;
      else
        t = 0;
      if (sum[r] - sum[l - 1] + t >= ans) {
        ans = sum[r] - sum[l - 1] + t;
        start = l;
        end = r;
      }
    }
  }
  cout << ans << " ";
  int num = 0;
  for (int i = start; i < end - 1; ++i) {
    if (arr[i] < 0) v.push_back(i + 1);
  }
  int sz = v.size();
  num += sz;
  num += (start - 1);
  num += (n - end);
  printf("%d\n", num);
  for (int i = 1; i < start; ++i) printf("%d ", i);
  for (int i = 0; i < sz; ++i) printf("%d ", v[i]);
  for (int i = end + 1; i <= n; ++i) printf("%d ", i);
  return 0;
}
