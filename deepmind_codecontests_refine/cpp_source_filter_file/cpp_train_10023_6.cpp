#include <bits/stdc++.h>
using namespace std;
int mt[2][2];
bool tran() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (mt[i][j] != mt[j][i]) return false;
    }
  }
  return true;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int c = 0;
    while (n--) {
      cin >> mt[0][0] >> mt[0][1] >> mt[1][0] >> mt[1][1];
      if (tran()) c++;
    }
    if (c != 0 && m % (2 * c) == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
