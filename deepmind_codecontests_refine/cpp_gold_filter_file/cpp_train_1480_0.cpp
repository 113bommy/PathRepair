#include <bits/stdc++.h>
long long int mod = 998244353;
long long int inf = (long long int)(1e18);
using namespace std;
mt19937 unlucko(chrono::steady_clock::now().time_since_epoch().count());
deque<int> ans;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (((b + d - a) > c || (b - a) >= c) && b) ans.push_front(1), --b;
  while (a && b) {
    --a, --b;
    ans.push_back(0);
    ans.push_back(1);
  }
  if ((a == 1 && (c || d)) || a > 1) {
    cout << "NO\n";
    return 0;
  } else if (a == 1)
    ans.push_back(0);
  while (b && c) {
    c--, b--;
    ans.push_back(2);
    ans.push_back(1);
  }
  if (b && (ans.empty() || ans.front() != 1)) ans.push_front(1), --b;
  if (b) {
    cout << "NO\n";
    return 0;
  }
  while (c && d) {
    c--;
    d--;
    ans.push_back(2);
    ans.push_back(3);
  }
  if (d && (ans.empty() || ans.front() == 2)) ans.push_front(3), --d;
  if (d) {
    cout << "NO\n";
    return 0;
  }
  if (c && (ans.empty() || ans.back() == 3 || ans.back() == 1))
    ans.push_back(2), --c;
  if (c) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (auto it : ans) cout << it << " ";
}
