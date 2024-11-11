#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000;
int used[MaxN + 1];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= MaxN; i++) used[i] = -1;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (int j = 1; j * j <= x; j++)
      if (x % j == 0) {
        if (used[j] == -1 || (used[j] != -1 && used[j] < i - y)) cnt++;
        if (j * j != x)
          if (used[x / j] == -1 || (used[x / j] != -1 && used[x / j] < i - y))
            cnt++;
      }
    cout << cnt << endl;
    for (int j = 1; j * j <= x; j++)
      if (x % j == 0) {
        used[j] = i;
        used[x / j] = i;
      }
  }
}
