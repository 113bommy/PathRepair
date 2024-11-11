#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, i, l = 0, r = 0, x;
  cin >> n;
  vector<pair<long long int, long long int>> v;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(make_pair(x, i + 1));
  }
  sort(v.begin(), v.end());
  string s;
  cin >> s;
  stack<long long int> s1;
  for (i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      cout << v[l].second << " ";
      s1.push(l);
      l++;
    } else {
      cout << v[s1.top()].second;
      s1.pop();
    }
  }
  return 0;
}
