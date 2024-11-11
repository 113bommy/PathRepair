#include <bits/stdc++.h>
using namespace std;
int const M = 1e6 + 5;
int md = 1e9 + 7;
int i, j, n, m, x, y, N, ans, t, k;
int a[M];
string s[100][2];
int main() {
  cin >> n >> m;
  if (m & 1 == 0)
    cout << (m + 1) / 2;
  else
    cout << n / 2 - m / 2 + 1;
}
