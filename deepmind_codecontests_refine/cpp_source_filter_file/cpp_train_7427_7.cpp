#include <bits/stdc++.h>
using namespace std;
long long NOD(long long NOD1, long long NOD2) {
  while (NOD2) {
    NOD1 %= NOD2;
    swap(NOD1, NOD2);
  }
  return NOD1;
}
long long NOK(long long NOK1, long long NOK2) {
  return NOK1 * NOK2 / NOD(NOK1, NOK2);
}
void faster() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void fopen() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
const int N = 2100;
int n, m, k, x, y, a, b;
int d[N][N], v[N][N];
bool lov(int c) {
  int l = max(1, x - c), r = min(n, x + c), t;
  for (int i = l; i < r; i++) {
    t = c - abs(i - x);
    if (y - t > 0 and !v[i][y - t]) {
      a = i;
      b = y - t;
      return true;
    }
    if (y + t <= m and !v[i][y + t]) {
      a = i;
      b = y + t;
      return true;
    }
  }
  return false;
}
int main() {
  faster();
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    for (int j = -2; j <= 2; j++) {
      for (int l = -2; l <= 2; l++) {
        if (x + j > n or x + j < 1 or y + l > m or y + l < 1) continue;
        d[x][y] = max(d[x][y], d[x + j][y + l] - abs(i) - abs(j));
      }
    }
    while (!lov(d[x][y])) {
      d[x][y]++;
    }
    v[a][b] = 1;
    cout << a << " " << b << '\n';
  }
}
