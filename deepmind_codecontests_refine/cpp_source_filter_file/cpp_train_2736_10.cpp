#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
int ans = 0;
char s[maxn][maxn];
struct P {
  int shux1, shuy1, shux2, shuy2, shux3, shuy3;
};
vector<P> v;
void mody4(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  v.push_back({x1, y1, x2, y2, x3, y3});
  v.push_back({x2, y2, x3, y3, x4, y4});
  v.push_back({x1, y1, x2, y2, x3, y3});
  v.push_back({x1, y1, x3, y3, x4, y4});
}
void mody3(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  if (s[x1][y1] == '0') {
    v.push_back({x2, y2, x3, y3, x4, y4});
  } else if (s[x2][y2] == '0') {
    v.push_back({x1, y1, x3, y3, x4, y4});
  } else if (s[x3][y3] == '0') {
    v.push_back({x1, y1, x2, y2, x4, y4});
  } else if (s[x4][y4] == '0') {
    v.push_back({x1, y1, x2, y2, x3, y3});
  }
}
void mody2(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  if (s[x1][y1] == '1' && s[x2][y2] == '1') {
    v.push_back({x2, y2, x3, y3, x4, y4});
    v.push_back({x1, y1, x3, y3, x4, y4});
  } else if (s[x3][y3] == '1' && s[x4][y4] == '1') {
    v.push_back({x4, y4, x1, y1, x2, y2});
    v.push_back({x3, y3, x1, y1, x2, y2});
  } else if (s[x1][y1] == '1' && s[x3][y3] == '1') {
    v.push_back({x3, y3, x2, y2, x4, y4});
    v.push_back({x1, y1, x2, y2, x4, y4});
  } else if (s[x2][y2] == '1' && s[x4][y4] == '1') {
    v.push_back({x4, y4, x1, y1, x3, y3});
    v.push_back({x2, y2, x1, y1, x3, y3});
  } else if (s[x1][y1] == '1' && s[x4][y4] == '1') {
    v.push_back({x2, y2, x3, y3, x4, y4});
    v.push_back({x1, y1, x2, y2, x3, y3});
  } else if (s[x2][y2] == '1' && s[x3][y3] == '1') {
    v.push_back({x1, y1, x3, y3, x4, y4});
    v.push_back({x1, y1, x2, y2, x4, y4});
  }
}
void mody1(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  if (s[x1][y1] == '1') {
    v.push_back({x1, y1, x2, y2, x3, y3});
    v.push_back({x3, y3, x1, y1, x4, y4});
    v.push_back({x1, y1, x2, y2, x4, y4});
  } else if (s[x2][y2] == '1') {
    v.push_back({x2, y2, x1, y1, x4, y4});
    v.push_back({x4, y4, x2, y2, x3, y3});
    v.push_back({x2, y2, x1, y1, x3, y3});
  } else if (s[x3][y3] == '1') {
    v.push_back({x3, y3, x1, y1, x4, y4});
    v.push_back({x4, y4, x2, y2, x3, y3});
    v.push_back({x1, y1, x2, y2, x3, y3});
  } else if (s[x4][y4] == '1') {
    v.push_back({x4, y4, x2, y2, x3, y3});
    v.push_back({x3, y3, x1, y1, x4, y4});
    v.push_back({x1, y1, x2, y2, x4, y4});
  }
}
void solve(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  int sum1 = 0;
  int sum0 = 0;
  if (s[x1][y1] == '1')
    sum1++;
  else
    sum0++;
  if (s[x2][y2] == '1')
    sum1++;
  else
    sum0++;
  if (s[x3][y3] == '1')
    sum1++;
  else
    sum0++;
  if (s[x4][y4] == '1')
    sum1++;
  else
    sum0++;
  if (sum1 == 4) {
    mody4(x1, y1, x2, y2, x3, y3, x4, y4);
    s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
    ans += 4;
  } else if (sum1 == 3) {
    mody3(x1, y1, x2, y2, x3, y3, x4, y4);
    s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
    ans += 1;
  } else if (sum1 == 2) {
    mody2(x1, y1, x2, y2, x3, y3, x4, y4);
    s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
    ans += 2;
  } else if (sum1 == 1) {
    mody1(x1, y1, x2, y2, x3, y3, x4, y4);
    s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
    ans += 3;
  } else if (sum1 == 0) {
    s[x1][y1] = s[x2][y2] = s[x3][y3] = s[x4][y4] = '0';
    ans += 0;
  }
}
int main(void) {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> s[i][j];
      }
    }
    for (int i = 1; i < n; i += 2) {
      for (int j = 1; j < m; j += 2) {
        solve(i, j, i, j + 1, i + 1, j, i + 1, j + 1);
      }
    }
    if (m & 1) {
      for (int i = 1; i < n; i += 2) {
        solve(i, m - 1, i, m, i + 1, m - 1, i + 1, m);
      }
    }
    if (n & 1) {
      for (int j = 1; j < m; j += 2) {
        solve(n - 1, j, n - 1, j + 1, n, j, n, j + 1);
      }
    }
    if ((n & 1) && (m & 1)) {
      solve(n - 1, m - 1, n - 1, m, n, m - 1, n, m);
    }
    cout << ans << endl;
    for (auto i : v) {
      cout << i.shux1 << " " << i.shuy1 << " " << i.shux2 << " " << i.shuy2
           << " " << i.shux3 << " " << i.shuy3 << endl;
    }
  }
  return 0;
}
