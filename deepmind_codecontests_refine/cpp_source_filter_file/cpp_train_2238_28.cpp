#include <bits/stdc++.h>
const double Pi = 3.14159265;
const double eps = 1e-10;
const double pi = acos(-1);
const int N = 1e6 + 10;
const int M = 2e5 + 10;
const unsigned long long base = 163;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;
int n;
vector<int> G[1010][1010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x / 1000][y / 1000].push_back(i);
  }
  for (int i = 0; i <= 1000; ++i) {
    if (i & 1)
      for (int j = 1000; j >= 0; --j) {
        for (int k : G[i][j]) printf("%d ", k);
      }
    else
      for (int j = 0; j <= 1000; ++j) {
        for (int k : G[i][j]) printf("%d ", k);
      }
  }
  return 0;
}
