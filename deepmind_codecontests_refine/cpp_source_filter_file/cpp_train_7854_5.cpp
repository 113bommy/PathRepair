#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[5001];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
  sort(arr, arr + n);
  int ans = 0, cur = 0;
  for (int i = 0; i < n; i++)
    if (arr[i].second < cur)
      ans = max(ans, arr[i].first);
    else
      cur = arr[i].second;
  cout << max(ans, cur) << endl;
  return 0;
}
