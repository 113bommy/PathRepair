#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[6][3]{{1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}, {0, 2, 1}, {0, 1, 2}};
int main() {
  cin >> n >> m;
  cout << p[n % 7 - 1][m];
  return 0;
}
