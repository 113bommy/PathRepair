#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int n, x;
  cin >> n;
  long long int b[n];
  map<long long int, long long int> mp;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    mp[abs(i + 1 - b[i])] += b[i];
  }
  long long int maxv = 0;
  for (auto x : mp) {
    maxv = max(maxv, x.second);
  }
  cout << maxv << endl;
  return 0;
}
