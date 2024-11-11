#include <bits/stdc++.h>
using namespace std;
string solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> odd;
  vector<int> even;
  for (int i = 0; i < n; i++) {
    if (i & 1)
      odd.push_back(a[i]);
    else
      even.push_back(a[i]);
  }
  if (even.size() % 2 == 0 && odd.size() % 2 == 0)
    return "YES";
  else {
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int i = 0, j = 0;
    while (i < odd.size() && j < even.size()) {
      if (abs(odd[i] - even[j]) == 1)
        return "YES";
      else {
        if (odd[i] > even[j])
          j++;
        else
          i++;
      }
    }
  }
  return "NO";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << '\n';
  }
  return 0;
}
