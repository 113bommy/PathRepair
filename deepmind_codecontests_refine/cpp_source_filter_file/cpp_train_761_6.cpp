#include <bits/stdc++.h>
using namespace std;
int n, x[3001], y[3001], ans;
bool point[2001][2001];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += 100;
    y[i] += 100;
    point[x[i]][y[i]] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if ((x[i] + x[j]) % 2 == 0 && (y[i] + y[j]) % 2 == 0)
        ans += point[(x[i] + x[j]) / 2][(y[i] + y[j]) / 2];
  cout << ans;
}
