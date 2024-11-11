#include <bits/stdc++.h>
using namespace std;
int inf_int = 2e9;
long long inf_ll = 1e18;
const double pi = 3.1415926535898;
template <typename T>
void prin(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i < a.size() - 1)
      cout << " ";
    else
      cout << "\n";
  }
}
template <typename T>
void prin(set<T>& a) {
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << " ";
  }
}
template <typename T>
void prin_new_line(vector<T>& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << "\n";
  }
}
template <typename T, typename T1>
void prin_new_line(vector<pair<T, T1> >& a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
int sum_vec(vector<int>& a) {
  int s = 0;
  for (int i = 0; i < a.size(); i++) {
    s += a[i];
  }
  return s;
}
template <typename T>
T max(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = max(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(vector<T>& a) {
  T ans = a[0];
  for (int i = 1; i < a.size(); i++) {
    ans = min(ans, a[i]);
  }
  return ans;
}
template <typename T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
long long dis(long long x, long long y, long long x1, long long y1) {
  return (x - x1) * (x - x1) + (y - y1) * (y - y1);
}
const int maxn = 5e5 + 100;
bool debug = 1;
void solve() {
  int n;
  cin >> n;
  stack<int> a;
  a.push(1);
  for (int i = 1; i < n; i++) {
    a.push(1);
    while (!a.empty()) {
      int x = a.top();
      a.pop();
      if (a.empty()) {
        a.push(x);
        break;
      }
      if (x == a.top()) {
        int y = a.top();
        a.pop();
        a.push(x + 1);
      } else {
        a.push(x);
        break;
      }
    }
  }
  vector<int> ans;
  while (!a.empty()) {
    ans.push_back(a.top());
    a.pop();
  }
  reverse(ans.begin(), ans.end());
  prin(ans);
}
int main() {
  if (!debug) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int t = 1;
  while (t--) solve();
  return 0;
}
