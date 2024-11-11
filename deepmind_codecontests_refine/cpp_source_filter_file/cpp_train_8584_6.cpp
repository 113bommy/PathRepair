#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 1e-9;
using namespace std;
int T[100005], D[300005][31];
int last = 0;
int getsum(int a, int b, int lo, int hi, int u) {
  if (b <= a) return 0;
  if (a == lo && b == hi) {
    int x = D[u][last];
    last = (last + x) % 30;
    return x;
  }
  int mid = (lo + hi) / 2;
  int L = getsum(a, min(b, mid), lo, mid, 2 * u);
  int P = getsum(max(a, mid), b, mid, hi, 2 * u + 1);
  return L + P;
}
void update(int u, int c) {
  for (int j = 0; j < 30; j++) {
    D[u][j] = 1;
    if (j % c == 0) D[u][j]++;
  }
  while (u != 1) {
    u /= 2;
    for (int j = 0; j < 30; j++) {
      int x = D[u * 2][j];
      D[u][j] = x + D[u * 2 + 1][(x + j) % 30];
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  int suma = 1;
  while (suma < n) suma *= 2;
  suma *= 2;
  suma--;
  for (int i = 1; i <= n; i++) cin >> T[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 30; j++) {
      D[i + suma / 2][j] = 1;
      if (j % T[i] == 0) D[i + suma / 2][j]++;
    }
  }
  for (int i = suma / 2; i >= 1; i--) {
    for (int j = 0; j < 30; j++) {
      int x = D[i * 2][j];
      D[i][j] = x + D[i * 2 + 1][(x + j) % 30];
    }
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    char c;
    cin >> c;
    int x, y;
    cin >> x >> y;
    if (c == 'A')
      cout << getsum(x, y, 1, suma / 2 + 2, 1) << "\n";
    else
      update(x + suma / 2, y);
    last = 0;
  }
  return 0;
}
