#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  unordered_map<long long int, long long int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  bool flag = true;
  for (auto x : mp) {
    if (x.second % 2 == 0) {
      flag = false;
      break;
    }
  }
  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[i + 1] && a[i] < a[i - 1]) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
