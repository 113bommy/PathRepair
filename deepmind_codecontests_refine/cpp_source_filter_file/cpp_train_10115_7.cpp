#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[500004];
char f(int i, int j) { return a[i * n + j]; }
long long mod = 1000003;
int main() {
  int i, j;
  char c;
  cin >> n >> m;
  for ((i) = 0; (i) < (n); (i)++)
    for ((j) = 0; (j) < (m); (j)++) {
      cin >> a[n * i + j];
    }
  long long ans = 1;
  for ((i) = 0; (i) < (n); (i)++) {
    int t1 = 0, t2 = 0;
    for ((j) = 0; (j) < (m); (j)++) {
      c = f(i, j);
      if (c >= '1' && c <= '4') {
        if (c == '1' || c == '2') {
          if (j % 2 == 0)
            t1 = 1;
          else
            t2 = 1;
        } else {
          if (j % 2 == 1)
            t1 = 1;
          else
            t2 = 1;
        }
      }
    }
    if (t1 && t2) ans = 0;
    if (!t1 && !t2) ans = (ans * 2) % mod;
  }
  for ((j) = 0; (j) < (m); (j)++) {
    int t1 = 0, t2 = 0;
    for ((i) = 0; (i) < (n); (i)++) {
      c = f(i, j);
      if (c >= '1' && c <= '4') {
        if (c == '1' || c == '4') {
          if (i % 2 == 1)
            t1 = 1;
          else
            t2 = 1;
        } else {
          if (i % 2 == 0)
            t1 = 1;
          else
            t2 = 1;
        }
      }
    }
    if (t1 && t2) ans = 0;
    if (!t1 && !t2) ans = (ans * 2) % mod;
  }
  cout << ans << endl;
  return 0;
}
