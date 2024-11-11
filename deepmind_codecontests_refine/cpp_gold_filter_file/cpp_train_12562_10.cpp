#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool s) { return to_string((int)s); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const long double eps = 1e-12;
const int N = 2e6 + 9;
int a[10][150];
int n, k;
vector<pair<int, pair<int, int>>> ans;
pair<int, int> prv(int i, int j) {
  if (i == 1) {
    if (j == 0) {
      i = 2;
      j = 0;
    } else {
      j--;
    }
  } else {
    if (j == n - 1) {
      i = 1;
      j = n - 1;
    } else {
      j++;
    }
  }
  return {i, j};
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[1][i] == a[0][i] && a[1][i] != 0) {
      ans.push_back({a[1][i], {0, i}});
      a[1][i] = a[0][i] = 0;
    }
    if (a[2][i] == a[3][i] && a[2][i] != 0) {
      ans.push_back({a[2][i], {3, i}});
      a[3][i] = a[2][i] = 0;
    }
  }
  int cnt = 0;
  int ei, ej;
  for (int i = 1; i <= 2; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != 0)
        cnt++;
      else
        ei = i, ej = j;
    }
  }
  if (cnt == 2 * n) return cout << "-1\n", 0;
  int tt = 2e6;
  while (tt--) {
    int ti, tj;
    tie(ti, tj) = prv(ei, ej);
    if (a[ti][tj] != 0) {
      ans.push_back({a[ti][tj], {ei, ej}});
    }
    a[ei][ej] = a[ti][tj];
    a[ti][tj] = 0;
    if (a[ei][ej] != 0) {
      if (ei == 1 && a[0][ej] == a[1][ej]) {
        ans.push_back({a[0][ej], {0, ej}});
        a[0][ej] = a[1][ej] = 0;
      } else if (ei == 2 && a[3][ej] == a[2][ej]) {
        ans.push_back({a[2][ej], {3, ej}});
        a[2][ej] = a[3][ej] = 0;
      }
    }
    ei = ti, ej = tj;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second.first + 1 << " "
         << ans[i].second.second + 1 << endl;
  }
  return 0;
}
