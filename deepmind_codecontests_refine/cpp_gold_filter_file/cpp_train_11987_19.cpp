#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  if (k * (k - 1) < n) {
    cout << "NO\n";
    return 0;
  }
  vector<pair<long long int, long long int> > ans;
  for (long long int i = k; i >= 1; i--) {
    for (long long int j = i - 1; j >= 1; j--) {
      if (i == j || ans.size() >= n) break;
      ans.push_back(make_pair(i, j));
      ans.push_back(make_pair(j, i));
    }
    if (ans.size() >= n) break;
  }
  cout << "YES\n";
  long long int c = 0;
  for (auto it : ans) {
    c++;
    cout << it.first << " " << it.second << endl;
    if (c == n) break;
  }
  return 0;
}
