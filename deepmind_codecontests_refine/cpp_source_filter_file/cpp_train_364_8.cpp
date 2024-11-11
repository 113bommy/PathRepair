#include <bits/stdc++.h>
using namespace std;
const int maxn = 200, inf = 1e9 + 10;
int a[maxn][maxn], N;
int mx = -1;
int ro(int i, int n) {
  bool fin = (i == n);
  int x = i / N;
  int y = i % N;
  return (fin ? -1 : (cin >> a[x][y], ro(i + 1, n)));
}
int ro2(int i, int n) {
  bool fin = (i == n);
  int x = i / (N * N);
  int y = (i % (N * N)) / N;
  int z = i % N;
  return (fin ? -1
              : (a[x][y] = min(a[x][y], a[x][z] + a[z][y]), ro2(i + 1, n)));
}
int ro3(int i, int n) {
  bool fin = (i == n);
  int x = i / N;
  int y = i % N;
  return (fin ? -1 : (mx = max(mx, a[x][y]), ro3(i + 1, n)));
}
int main() {
  cin >> N;
  ro(0, N * N);
  ro2(0, N * N * N);
  ro3(0, N * N);
  cout << mx << endl;
}
