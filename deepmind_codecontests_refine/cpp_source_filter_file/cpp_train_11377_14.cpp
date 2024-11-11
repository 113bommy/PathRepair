#include <bits/stdc++.h>
using namespace std;
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
  int n;
  string s;
  cin >> n >> s;
  int c = 0;
  vector<vector<int> > occ(n + 1, vector<int>());
  vector<int> last(n + 1, -1);
  vector<int> cval(n + 1, 0);
  vector<int> ptr(n + 1, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      c++;
    else
      c = 0;
    cval[i] = c;
    occ[c].push_back(i);
  }
  long long int ans = 0;
  for (int i = 0; i <= n; i++) occ[i].push_back(n);
  for (int i = 0; i < n; i++) {
    long long int c = cval[i];
    ++ptr[c];
    if (!c) continue;
    if (last[c] != -1) ans += (i - (last[c] + c)) * c;
    ans += 1ll * (i - c - last[c + 1]) * c + (c * (c + 1)) / 2;
    if (!cval[i + 1]) {
      ans += 1ll * (i - c - last[c + 1]) * (occ[c][ptr[c]] - (i + 1)) * c;
      for (int j = i; j > i - c; j--) {
        last[i - j + 1] = j;
      }
    }
  }
  for (long long int c = cval[n - 1] + 1; c <= n; c++)
    if (last[c] != -1) ans += (n - (last[c] + c)) * c;
  cout << ans;
}
