#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  map<int, long long> mp;
  for (int i = 0; i < n; i++) mp[arr[i] - (i + 1)] += arr[i];
  vector<long long> v;
  map<int, long long>::iterator it = mp.begin();
  while (it != mp.end()) {
    v.push_back(it->second);
    it++;
  }
  sort(v.begin(), v.end());
  int d = v.size();
  cout << v[d - 1];
  return 0;
}
