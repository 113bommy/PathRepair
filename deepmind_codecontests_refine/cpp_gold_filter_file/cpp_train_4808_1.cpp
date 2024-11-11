#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e3 + 5;
int arr[maxN], n;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0),
      cout.precision(15);
  cin >> n;
  for (int i = int(0); i < int(n); i++) cin >> arr[i];
  int ans = 1000000000;
  for (int i = int(-1); i < int(n); i++) {
    set<int> s;
    for (int j = 0; j <= i; j++) {
      if (s.find(arr[j]) != s.end()) break;
      s.insert(arr[j]);
    }
    for (int j = n - 1; j > i; j--) {
      if (s.find(arr[j]) != s.end()) break;
      s.insert(arr[j]);
    }
    ans = min(ans, n - (int)s.size());
  }
  cout << ans;
  return 0;
}
