#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  pair<long long int, long long int> arr[n];
  long long int sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i].first;
    cin >> arr[i].second;
    sum += arr[i].first;
  }
  sort(arr, arr + n, cmp);
  long long int st = 0, ans = 0;
  for (long long int i = 1; i <= 62; i++) {
    long long int en = st;
    while (en < n && arr[en].second < (long long int)((long long int)1 << i))
      en++;
    long long int nwsum = 0;
    for (long long int j = st; j < en; j++) {
      long long int val = __builtin_popcount(ans & arr[j].second);
      if (val & 1)
        nwsum += (-arr[j].first);
      else
        nwsum += arr[j].first;
    }
    if ((nwsum > 0 && sum > 0) || (nwsum < 0 && sum < 0))
      ans += (long long int)((long long int)1 << (i - 1));
    st = en;
  }
  cout << ans << endl;
  return 0;
}
