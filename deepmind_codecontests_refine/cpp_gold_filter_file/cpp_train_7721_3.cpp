#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int arr[m];
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  long long int ans = 0;
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    map<char, int> mp;
    map<char, int>::iterator it;
    for (int j = 0; j < n; j++) {
      mp[a[j][i]]++;
    }
    for (it = mp.begin(); it != mp.end(); it++) {
      if (it->second > cnt) cnt = it->second;
    }
    ans += cnt * arr[i];
  }
  cout << ans;
}
