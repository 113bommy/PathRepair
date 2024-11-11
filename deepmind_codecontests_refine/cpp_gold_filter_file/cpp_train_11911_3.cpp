#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  scanf("%d", &n);
  int arr[n], num[100001] = {};
  pair<int, int> diff[100001] = {{}};
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &arr[i]);
    if (diff[arr[i]].first == 0)
      diff[arr[i]].first = i + 1;
    else if (diff[arr[i]].second == 0)
      diff[arr[i]].second = i + 1;
    else if (i + 1 - diff[arr[i]].second ==
             diff[arr[i]].second - diff[arr[i]].first) {
      diff[arr[i]].first = diff[arr[i]].second;
      diff[arr[i]].second = i + 1;
    } else
      num[arr[i]] = -1;
    if (num[arr[i]] != -1) num[arr[i]]++;
  }
  int cnt = 0;
  for (int i = 0; i <= 100000; i++)
    if (num[i] > 0) cnt++;
  printf("%d\n", cnt);
  for (int i = 0; i <= 100000; i++) {
    if (num[i] > 0)
      printf("%d %d\n", i,
             (diff[i].second > 0) ? diff[i].second - diff[i].first : 0);
  }
  return 0;
}
