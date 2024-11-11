#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
int N;
bool e[MAXN][MAXN];
bool even[6][6] = {{0, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 1, 0}, {0, 0, 0, 1, 0, 1},
                   {0, 0, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 1}, {1, 1, 0, 0, 0, 0}};
int main() {
  cin >> N;
  if (N == 4) {
    cout << -1 << '\n';
    return 0;
  }
  if (N % 2 == 1) {
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if ((j - i) % 2 == 1)
          e[i][j] = 1;
        else
          e[j][i] = 1;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) cout << e[i][j] << ' ';
      cout << '\n';
    }
  } else {
    for (int i = 0; i < 36; i++) e[i / 6][i % 6] = even[i / 6][i % 6];
    for (int i = 0; i < N; i++) {
      for (int j = max(i + 1, 6); j < N; j++) {
        if ((j - i) % 2 == 1)
          e[i][j] = 1;
        else
          e[j][i] = 1;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) cout << e[i][j] << ' ';
      cout << '\n';
    }
  }
}
