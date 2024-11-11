#include <bits/stdc++.h>
using namespace std;
int m, ans = 99999999, n, k;
vector<int> v;
int main(int argc, char const *argv[]) {
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> v;
  m = k / 2;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == '0') v.push_back(i);
  for (int i = 0; i < v.size() - k; i++) {
    int a = v[i], b = v[i + k];
    int mid = a + b >> 1;
    int p = upper_bound(v.begin(), v.end(), mid) - v.begin();
    ans = min(ans, max(v[p] - v[i], v[i + k] - v[p]));
    p--;
    ans = min(ans, max(v[p] - v[i], v[i + k] - v[p]));
  }
  cout << ans;
  return 0;
}
