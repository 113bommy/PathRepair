#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 5;
int n, m, t[maxn], dq[maxn], front, back;
long long s[maxn];
double a[maxn], b[maxn], f[maxn][51];
double get(int i, int j, int k) {
  return -s[j] * b[i] + f[j][k - 1] + b[j] * s[j] - a[j];
}
long long A(int x, int k) { return -s[x]; }
double B(int x, int k) { return f[x][k - 1] + b[x] * s[x] - a[x]; }
bool better(int x, int y, int z, int k) {
  return (B(y, k) - B(z, k)) * (A(x, k) - A(z, k)) >=
         (B(x, k) - B(z, k)) * (A(y, k) - A(z, k));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + t[i];
    a[i] = a[i - 1] + 1.0 * s[i] / t[i];
    b[i] = b[i - 1] + 1.0 / t[i];
  }
  for (int i = 1; i <= n; i++) f[i][0] = 1e18;
  for (int k = 1; k <= m; k++) {
    front = back = 0;
    dq[0] = k - 1;
    for (int i = k; i <= n; i++) {
      while (front < back && get(i, dq[front], k) >= get(i, dq[front + 1], k))
        front++;
      f[i][k] = get(i, dq[front], k) + a[i];
      while (front < back && better(dq[back - 1], dq[back], i, k)) back--;
      dq[++back] = i;
    }
  }
  cout << fixed << setprecision(10) << f[n][m] << endl;
}
