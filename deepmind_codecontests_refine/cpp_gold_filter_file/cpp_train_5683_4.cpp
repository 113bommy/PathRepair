#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll d[20][400000];
vector<int> ans;
int main(int argc, char const *argv[]) {
  string s;
  cin >> s;
  s += s;
  int m;
  cin >> m;
  for (int i = 0; i < s.size(); ++i) {
    d[0][i] = s[i] - '0';
  }
  ll p = 10 % m, f = 1;
  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      if (j - f >= 0) {
        d[i][j] = d[i - 1][j];
        d[i][j] = (d[i][j] + d[i - 1][j - f] * p) % m;
      } else {
        d[i][j] = -1;
      }
    }
    f = f << 1;
    p = (p * p) % m;
  }
  for (int j = s.size() / 2 - 1; j < s.size() - 1; ++j) {
    int l = j + 1 - s.size() / 2;
    if (s[l] != '0') {
      ll w = j;
      ll v = 0;
      ll u = 0;
      ll f = 1;
      ll e = 1;
      ll b = 10 % m;
      for (int i = s.size() / 2; i; i /= 2) {
        if (i & 1) {
          v = (v + d[u][w] * e) % m;
          w -= f;
          e = e * b % m;
        }
        f = f * 2;
        u = u + 1;
        b = b * b % m;
      }
      ans.push_back(v);
    }
  }
  printf("%d\n", min_element(ans.begin(), ans.end())[0]);
  return 0;
}
