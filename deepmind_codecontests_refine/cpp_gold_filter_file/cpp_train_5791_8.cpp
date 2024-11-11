#include <bits/stdc++.h>
using namespace std;
const int N = int(4e5) + 5;
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e17 + 7;
const long double eps = 1e-7;
int n;
string s[N], now, won;
unordered_map<string, int> m, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    m.clear();
    for (int x = 0; x < 9; x++) {
      for (int y = x; y < 9; y++) {
        now = "";
        for (int q = x; q <= y; q++) {
          now += s[i][q];
          if (!m[now]) m[now] = 1, ans[now]++;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int ok = 17;
    for (int x = 0; x < 9; x++) {
      for (int y = x; y < 9; y++) {
        now = "";
        for (int q = x; q <= y; q++) now += s[i][q];
        if (ans[now] == 1 && now.size() < ok) ok = now.size(), won = now;
      }
    }
    cout << won << "\n";
  }
  return 0;
}
