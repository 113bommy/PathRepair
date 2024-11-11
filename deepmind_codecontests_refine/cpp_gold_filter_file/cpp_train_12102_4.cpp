#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll MOD = 1e9 + 7;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void chmax(T &a, T b) {
  a = max(a, b);
}
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
template <class T>
void readv(vector<T> &v) {
  for (int i = 0; i < v.size(); i++) cin >> v[i];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      st.insert(a);
    }
    if (st.size() > k) {
      cout << -1 << '\n';
      continue;
    }
    cout << k * n << '\n';
    for (int i = 0; i < n; i++) {
      for (auto it = st.begin(); it != st.end(); it++) {
        cout << (*it);
        if (next(it) == st.end() && i + 1 == n && st.size() == k) {
          cout << '\n';
        } else {
          cout << " ";
        }
      }
      for (int j = 0; j < k - st.size(); j++) {
        cout << 1;
        if (i + 1 == n && j + 1 == k - st.size()) {
          cout << '\n';
        } else {
          cout << " ";
        }
      }
    }
  }
}
