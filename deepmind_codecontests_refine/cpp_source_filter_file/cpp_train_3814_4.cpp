#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 24;
int days[MAXN], poss[2 * MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> days[i];
  for (int i = 0; i < 5; i++) {
    int x = 12 * i;
    poss[x + 0] = 31, poss[x + 1] = 28, poss[x + 2] = 31, poss[x + 3] = 30,
             poss[x + 4] = 31, poss[x + 5] = 30, poss[x + 6] = 31,
             poss[x + 7] = 31, poss[x + 8] = 30, poss[x + 9] = 31,
             poss[x + 10] = 30, poss[x + 11] = 31;
  }
  poss[13] = 29;
  for (int i = 0; i < 36; i++) {
    bool done = true;
    for (int j = 0; j < n; j++)
      if (days[j] != poss[j + i]) done = false;
    if (done) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}
