#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[6][6];
  for (int i = 1; i <= 5; i++)
    for (int j = 1; j <= 5; j++) cin >> arr[i][j];
  int p[6];
  for (int i = 1; i <= 5; i++) p[i] = i;
  int maxe = -1;
  int res;
  do {
    res = 0;
    for (int i = 1; i <= 5; i++) {
      for (int j = i; j < 5; j += 2) {
        int x = p[j], y = p[j + 1];
        res += (arr[x][y] + arr[y][x]);
      }
    }
    maxe = max(res, maxe);
  } while (next_permutation(p + 1, p + 6));
  cout << maxe;
}
