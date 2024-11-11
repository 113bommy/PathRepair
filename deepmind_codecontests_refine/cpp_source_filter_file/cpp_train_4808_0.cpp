#include <bits/stdc++.h>
using namespace std;
int64_t max(int64_t a, int64_t b) { return (a > b) ? a : b; }
int main() {
  int64_t i, j, k, n;
  cin >> n;
  vector<int64_t> arr(n);
  for (i = 0; i < n; ++i) cin >> arr[i];
  int64_t left = 1, right = 1, middle = 1;
  set<int64_t> s;
  for (i = 0; i < n; ++i) {
    if (s.find(arr[i]) != s.end()) break;
    s.insert(arr[i]);
  }
  s.clear();
  left = i;
  reverse(arr.begin(), arr.end());
  for (i = 0; i < n; ++i) {
    if (s.find(arr[i]) != s.end()) break;
    s.insert(arr[i]);
  }
  reverse(arr.begin(), arr.end());
  right = i;
  if (left == n) {
    cout << "0\n";
    return 0;
  }
  s.clear();
  int64_t ans = 1;
  for (i = 0; i < left; ++i) {
    s.insert(arr[i]);
    set<int64_t> s1;
    s1 = s;
    for (j = n - 1; j >= 0; --j) {
      if (s1.find(arr[j]) == s1.end())
        s1.insert(arr[j]);
      else
        break;
    }
    ans = max(ans, s1.size());
  }
  cout << min(n - max(left, right), ans) << "\n";
  return 0;
}
