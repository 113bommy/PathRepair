#include <bits/stdc++.h>
using namespace std;
int n, f[101][101];
int main() {
  cin >> n;
  int now;
  for (int i = 3; i <= 100; i++) {
    now = i + 1;
    if (now * (now - 1) * (now - 2) / 6 > n) {
      now--;
      break;
    }
  }
  int ans = now * (now - 1) * (now - 2) / 6;
  for (int i = 1; i < now; i++)
    for (int j = i + 1; j <= now; j++) f[i][j] = f[j][i] = 1;
  int tot = now;
  while (ans != n) {
    int i = 2;
    for (; i <= tot; i++)
      if ((i + 1) * i / 2 + ans > n) break;
    now++;
    for (int j = 1; j <= i; j++) f[now][j] = f[j][now] = 1;
    ans += i * (i - 1) / 2;
  }
  cout << now << endl;
  for (int i = 1; i <= now; i++) {
    for (int j = 1; j <= now; j++) cout << f[i][j];
    cout << endl;
  }
}
