#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char **argv) {
  if (argc >= 2) {
    freopen(argv[1], "r", stdin);
  }
  int n;
  cin >> n;
  n %= 6;
  int x;
  cin >> x;
  int a[3][6] = {{0, 1, 2, 2, 1, 0}, {1, 0, 0, 1, 2, 1}, {2, 2, 1, 0, 0, 2}};
  for (int i = 0; i < 3; i++) {
    if (a[i][n] == x) {
      cout << i << endl;
    }
  }
}
