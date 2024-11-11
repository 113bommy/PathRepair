#include <bits/stdc++.h>
using namespace std;
long long n, a[100005];
map<long long, long long> m;
vector<vector<int>> ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (n % 2 == 0) {
    long long val = 0;
    for (int i = 0; i < n; ++i) val = val ^ a[i];
    if (val != 0) {
      cout << "NO";
      return 0;
    }
    n -= 1;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n;) {
    if (i + 2 > n) break;
    vector<int> tmp(3);
    tmp[0] = i + 1;
    tmp[1] = i + 2;
    tmp[2] = i + 3;
    i += 2;
    ans.push_back(tmp);
  }
  for (int i = 0; i < n;) {
    if (i + 2 > n - 3) break;
    vector<int> tmp(3);
    tmp[0] = i + 1;
    tmp[1] = i + 2;
    tmp[2] = n;
    i += 2;
    ans.push_back(tmp);
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it[0] << " " << it[1] << " " << it[2] << endl;
  }
}
