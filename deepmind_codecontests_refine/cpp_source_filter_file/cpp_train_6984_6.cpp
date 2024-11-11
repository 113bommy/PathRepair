#include <bits/stdc++.h>
using namespace std;
long long gcd1(long long a, long long b) {
  if (a == 0) return b;
  return gcd1(b % a, a);
}
long long modx(long long base, long long ex) {
  long long ans = 1LL, val = base;
  while (ex > 0LL) {
    if (ex & 1LL) ans = (ans * val) % 1000000009LL;
    val = (val * val) % 1000000009LL;
    ex = ex >> 1LL;
  }
  return ans;
}
char grid[105][105];
bool visit[105][105];
int l[105][105], r[105][105], u[105][105], d[105][105];
vector<pair<pair<int, int>, int> > v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> grid[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (grid[i][j] == '*' && grid[i][j + 1] == '*') r[i][j] = r[i][j + 1] + 1;
    }
    for (int j = 1; j <= m; j++) {
      if (grid[i][j] == '*' && grid[i][j - 1] == '*') l[i][j] = l[i][j - 1] + 1;
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i >= 1; i--) {
      if (grid[i][j] == '*' && grid[i + 1][j] == '*') d[i][j] = d[i + 1][j] + 1;
    }
    for (int i = 1; i <= n; i++) {
      if (grid[i][j] == '*' && grid[i - 1][j] == '*') u[i][j] = u[i - 1][j] + 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      int ry = min(l[i][j], min(r[i][j], min(u[i][j], d[i][j])));
      if (ry == 0) continue;
      visit[i][j] = true;
      v.push_back(make_pair(make_pair(i, j), ry));
      int i1 = i + 1, j1 = j + 1;
      while (i1 <= i + ry) {
        visit[i1][j] = true;
        i1++;
      }
      while (j1 <= j + ry) {
        visit[i][j1] = true;
        j1++;
      }
      i1 = i - 1;
      j1 = j - 1;
      while (i1 >= i - ry) {
        visit[i1][j] = true;
        i1--;
      }
      while (j1 >= j - ry) {
        visit[i][j1] = true;
        j1--;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (grid[i][j] == '*' && !visit[i][j]) {
        cout << "-1" << endl;
        return 0;
      }
  cout << v.size() << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second
         << endl;
  return 0;
}
