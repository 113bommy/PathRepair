#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int ar[6][3] = {{0, 1, 2}, {1, 0, 2}, {1, 2, 0},
                {2, 1, 0}, {2, 0, 1}, {0, 2, 1}};
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  cout << ar[(n - 1) % 6][m - 1] << endl;
}
