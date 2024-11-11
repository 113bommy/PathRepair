#include <bits/stdc++.h>
using namespace std;
char in[10][36];
int c[10];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%s%d", in[i], c + i);
  }
  vector<bool> bs(n - c[0]);
  for (int i = 0; i < c[0]; i++) {
    bs.push_back(true);
  }
  int ret = 0;
  do {
    bool ok = true;
    for (int i = 1; i < m; i++) {
      int d = 0;
      for (int j = 0; j < n; j++) {
        if (bs[j] == (in[0][j] == in[i][j])) {
          d++;
        }
      }
      if (d != c[i]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ret++;
    }
  } while (next_permutation(bs.begin(), bs.end()));
  printf("%d\n", ret);
  return 0;
}
