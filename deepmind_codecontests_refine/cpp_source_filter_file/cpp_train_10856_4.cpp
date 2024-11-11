#include <bits/stdc++.h>
using namespace std;
const int mxn = 200000;
int n;
int t[mxn], a[mxn];
vector<int> v;
set<int> second, s2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    char c;
    cin >> c;
    if (t[i] = c == '-') cin >> a[i];
  }
  for (int i = 2 * n - 1; ~i; i--) {
    if (t[i]) {
      second.insert(a[i]);
      second.insert(i);
    } else {
      if (second.empty() || a[*s2.begin()] != *second.begin()) {
        cout << "NO" << '\n';
        return 0;
      }
      v.push_back(*second.begin());
      second.erase(second.begin());
      s2.erase(s2.begin());
    }
  }
  reverse(v.begin(), v.end());
  cout << "YES" << '\n';
  cout << v[0];
  for (int i = 1; i < n; i++) cout << " " << v[i];
  cout << '\n';
  return 0;
}
