#include <bits/stdc++.h>
using namespace std;
void print(int a[], int n) {
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
}
void iarr(int *a, int n) {
  for (long long i = 0; i < n; i++) cin >> a[i];
}
void input(vector<int> &v) {
  for (auto &i : v) cin >> i;
}
int dim[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                {0, 1},   {1, -1}, {1, 0},  {1, 1}};
const int N = 1001;
bool isValid(int x, int y, int n) {
  if (x > 0 and y > 0 and x <= n and y < n) return true;
  return false;
}
bool path(int vis[N][N], int i, int j, int P, int Q, int x3, int y3, int n) {
  if (i < 1 or j < 1 or i > n or j > n) return false;
  if (Q - j == 0 or P - i == 0 or abs(P - i) == abs(Q - j)) return false;
  if (i == x3 and j == y3) {
    return true;
  }
  vis[i][j] = 1;
  for (long long k = 0; k < 8; k++) {
    int newX = i + dim[k][0], newY = j + dim[k][1];
    if (isValid(newX, newY, n) and vis[newX][newY] == 0) {
      if (path(vis, newX, newY, P, Q, x3, y3, n)) return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed;
  cout.precision(10);
  ;
  int P, Q, x2, y2, x3, y3, n;
  cin >> n;
  cin >> P >> Q;
  cin >> x2 >> y2;
  cin >> x3 >> y3;
  int vis[N][N];
  memset(vis, 0, sizeof(vis));
  bool temp = path(vis, x2, y2, P, Q, x3, y3, n);
  cout << (temp == true ? "YES" : "NO") << "\n";
  return 0;
}
