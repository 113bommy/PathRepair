#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
template <typename X>
using matrix = vector<vector<X>>;
const ll INF = (ll)1e9 + 6ll;
const vector<int> DX = {+1, -1, 0, 0, +1, -1, -1, +1};
const vector<int> DY = {0, 0, +1, -1, +1, -1, +1, -1};
template <typename X>
bool soft(X& a, const X b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename X>
bool strong(X& a, const X b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
void freeopen() {}
void reflex() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  freeopen();
}
signed main() {
  reflex();
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2) {
      if (s[0] >= s[1])
        cout << "NO\n";
      else
        cout << "YES\n2\n" << s[0] << " " << s[1] << "\n";
    } else {
      cout << "YES\n2\n";
      cout << s.front() << " ";
      for (int i = 1; i < n; i++) cout << s[i];
      cout << "\n";
    }
  }
  return false;
}
