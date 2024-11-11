#include <bits/stdc++.h>
using namespace std;
int const N = 1000005;
long double pi = 3.14159265359;
long long const mod = 1e9 + 7;
void FAST() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void TXT() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
int main() {
  FAST();
  int n, m, p;
  cin >> n >> m >> p;
  int f = 0, s = 0, x = -1, y = -1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a % p != 0 && x == -1) {
      f = i;
      x = i;
    }
  }
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    if (b % p != 0 && y == -1) {
      s = i;
      y = i;
    }
  }
  cout << f + s;
}
