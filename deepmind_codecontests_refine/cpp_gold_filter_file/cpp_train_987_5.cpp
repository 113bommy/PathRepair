#include <bits/stdc++.h>
using namespace std;
bool comp(const pair<long long int, long long int> &a,
          const pair<long long int, long long int> &b) {
  return a.first < b.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, d;
  cin >> n >> d;
  vector<pair<long long int, long long int> > arr(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end(), comp);
  long long int ma = 0;
  vector<long long int> cum(n);
  cum[0] = arr[0].second;
  for (__typeof(n) i = (1) - ((1) > (n)); i != (n) - ((1) > (n));
       i += 1 - 2 * ((1) > (n)))
    cum[i] = cum[i - 1] + arr[i].second;
  vector<long long int> temp(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    temp[i] = arr[i].first;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    auto it = upper_bound(temp.begin(), temp.end(), temp[i] + d - 1);
    long long int index = it - temp.begin();
    if (index < n && (temp[index] >= d + temp[i])) index--;
    if (index == n) index--;
    long long int temp_ans;
    if (i == 0)
      temp_ans = cum[index];
    else
      temp_ans = cum[index] - cum[i - 1];
    ma = max(ma, temp_ans);
  }
  cout << ma;
  return 0;
}
