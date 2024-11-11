#include <bits/stdc++.h>
using namespace std;
int bs(int first, int begin, int end, int a[], int key);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a(n);
    map<int, int, greater<int>> cnt;
    int maxFreq = INT_MIN;
    for (auto it : a) {
      cin >> it;
      if (it % k == 0) continue;
      ++cnt[k - it % k];
      maxFreq = max(maxFreq, cnt[k - it % k]);
    }
    long long ans = 0;
    for (auto it : cnt) {
      if (it.second == maxFreq) {
        ans = k * 1LL * (it.second - 1) + it.first + 1;
        break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
int bs(int begin, int end, int arr[], int key) {
  if (begin <= end) {
    int mid = (begin + end) / 2;
    if (arr[mid] == key)
      return mid + 1;
    else if (arr[mid] < key)
      return bs(mid + 1, end, arr, key);
    else
      return bs(begin, mid - 1, arr, key);
  }
  return -1;
}
