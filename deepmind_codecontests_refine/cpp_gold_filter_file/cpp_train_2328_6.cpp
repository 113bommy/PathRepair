#include <bits/stdc++.h>
using namespace std;
int solve(void) {
  int N, M, X, minans, maxans;
  cin >> N >> M >> X;
  minans = N - 1;
  maxans = ((N - 1) * (N - 2)) / 2 + 1;
  if (minans <= M && M <= maxans) {
    for (int i = 1; i < (int)N + 1 && M; i += 1)
      if (i != X && M) cout << i << " " << X << endl, M -= 1;
    if (X == 1) {
      for (int i = 1; i < (int)N + 1 && M; i += 1)
        if (i != 2 && i != X && M)
          for (int j = i + 1; j < (int)N + 1 && M; j += 1)
            if (j != 2 && j != X && M) {
              cout << i << " " << j << endl;
              M -= 1;
            }
    } else {
      for (int i = 2; i < (int)N + 1 && M; i += 1)
        if (i != X && M)
          for (int j = i + 1; j < (int)N + 1 && M; j += 1)
            if (j != X && M) {
              cout << i << " " << j << endl;
              M -= 1;
            }
    }
  } else {
    cout << -1 << endl;
    ;
  }
  return 0;
}
int main(void) {
  solve();
  return 0;
}
