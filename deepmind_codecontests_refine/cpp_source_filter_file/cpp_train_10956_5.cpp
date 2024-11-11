#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
bool MinPlace(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
bool MaxPlace(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename S, typename T>
ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    out << v[i];
    if (i != (int)v.size() - 1) out << ", ";
  }
  out << "]";
  return out;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<long long int> nos;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      nos.push_back(stoll(s, nullptr, 2));
    }
    sort(nos.begin(), nos.end());
    nos.push_back((1ll << m) + 1);
    long long int ans = -1, need = ((1ll << m) - n + 1) / 2;
    for (int i = 0; i < nos.size(); i++)
      if (nos[i] - i >= need) {
        ans = nos[i] - 1 - (nos[i] - i - need);
        break;
      }
    string s(m, '0');
    for (int i = 0; i < m; i++)
      if (ans & (1 << i)) s[m - 1 - i]++;
    cout << s << "\n";
  }
};
