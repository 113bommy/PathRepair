#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans = 0, count = 0;
  cin >> n;
  vector<int> a(n);
  map<int, int> asd;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    asd[a[i]]++;
  }
  sort(a.begin(), a.end());
  for (auto it = asd.begin(); it != asd.end(); it++) {
    if (it->second > 2) {
      cout << "cslnb";
      return 0;
    } else if (it->second == 2) {
      count++;
      if (count > 1) {
        cout << "cslnb";
        return 0;
      }
      if (it->first == 0) {
        cout << "cslnb";
        return 0;
      }
      if (asd.find(it->first - 1) != asd.end()) {
        cout << "cslnb";
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    ans += abs(i - a[i]);
  }
  if (ans % 2 == 0) {
    cout << "cslnb";
  } else {
    cout << "sjfnb";
  }
  return 0;
}
