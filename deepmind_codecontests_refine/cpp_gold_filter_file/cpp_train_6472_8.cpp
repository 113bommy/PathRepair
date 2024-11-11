#include <bits/stdc++.h>
using namespace std;
long long h[3008][3008];
long long mat[3008][3008];
long long n, m, a, b, g, x, y, z;
deque<int> que;
int main() {
  cin >> n >> m >> a >> b >> g >> x >> y >> z;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      h[i][j] = g;
      g = (g * x + y) % z;
    }
  }
  for (int i = 1; i <= n; ++i) {
    que.clear();
    for (int j = 1; j < b; ++j) {
      while (!que.empty() && h[i][que.back()] > h[i][j]) que.pop_back();
      que.push_back(j);
    }
    for (int j = b; j <= m; ++j) {
      while (!que.empty() && que.front() <= j - b) que.pop_front();
      while (!que.empty() && h[i][que.back()] > h[i][j]) que.pop_back();
      que.push_back(j);
      mat[i][j] = h[i][que.front()];
    }
  }
  long long ans = 0;
  for (int j = b; j <= m; ++j) {
    que.clear();
    for (int i = 1; i < a; ++i) {
      while (!que.empty() && mat[que.back()][j] > mat[i][j]) que.pop_back();
      que.push_back(i);
    }
    for (int i = a; i <= n; ++i) {
      while (!que.empty() && que.front() <= i - a) que.pop_front();
      while (!que.empty() && mat[que.back()][j] > mat[i][j]) que.pop_back();
      que.push_back(i);
      ans += mat[que.front()][j];
    }
  }
  printf("%I64d\n", ans);
}
