#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const int len = (int)2e5;
int a[len];
int main() {
  int k, n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    vector<int> v;
    while (j < n && s[j] == s[i]) {
      v.push_back(a[j]);
      j++;
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int l = 0; l < min(k, (int)v.size()); l++) {
      ans += v[l];
    }
    i = j - 1;
  }
  cout << ans << endl;
  return 0;
}
