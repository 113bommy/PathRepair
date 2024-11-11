#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i;
  cin >> n;
  long long int arr[n + 1];
  vector<long long int> x, y;
  map<long long int, long long int> mp;
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    mp[arr[i]]++;
  }
  for (auto it : mp) {
    if (it.second > 2) {
      cout << "NO" << endl;
      return 0;
    } else if (it.second == 2) {
      x.push_back(it.first);
      y.push_back(it.first);
    } else if (it.second == 1) {
      x.push_back(it.first);
    }
  }
  sort(x.begin(), x.end());
  sort(x.begin(), x.end(), greater<long long int>());
  cout << "YES" << endl;
  cout << x.size() << endl;
  for (auto it : x) {
    cout << it << " ";
  }
  cout << endl;
  cout << y.size() << endl;
  for (auto it : y) {
    cout << it << " ";
  }
  return 0;
}
