#include <bits/stdc++.h>
using namespace std;
deque<int> v, vc, t;
int x, m, n, r, l, q, T, p, cnt = 0, mx, ans = 0, sum = 0, y, mn = 1e18;
map<long long, long long> mp;
string s, s1, g;
char xz;
int main() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> y;
    ans += y;
    v.push_back(y);
  }
  cnt = *max_element(v.begin(), v.end());
  for (int i = 0; i < 101; i++) {
    if (i >= cnt) {
      for (int j = 0; j < v.size(); j++) {
        sum += (i - v[j]);
      }
      if (sum > ans) return cout << i, 0;
      sum = 0;
    }
  }
}
