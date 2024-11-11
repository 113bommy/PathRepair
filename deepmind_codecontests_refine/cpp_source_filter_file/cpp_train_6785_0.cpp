#include <bits/stdc++.h>
using namespace std;
long long a[100007];
long long dis[130][130], Map[130][130];
int main() {
  long long n, x;
  cin >> n;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x != 0) a[++c] = x;
  }
  n = c;
  if (n > 128)
    cout << 3 << endl;
  else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if ((a[i] & a[j]) && (i != j)) {
          dis[i][j] = Map[i][j] = 1;
        } else {
          dis[i][j] = Map[i][j] = 10086;
        }
      }
    }
    long long s = 10086;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        for (int k = 1; k < i; k++) {
          s = min(s, dis[j][k] + Map[j][i] + Map[i][k]);
        }
      }
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
        }
      }
    }
    if (s > n)
      cout << -1 << endl;
    else
      cout << s << endl;
  }
}
