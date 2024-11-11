#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int Ans[1000005];
int main() {
  long long n, x = 0, a[100007], b, c, d;
  a[0] = 1;
  while (scanf("%d", &n) != EOF) {
    cout << n * (n + 1) << endl;
    x = 0;
    for (int i = 1; a[i - 1] <= n; i++) {
      a[i] = a[i - 1] * 2;
      x++;
    }
    for (int i = 0; i <= n; i++) {
      int p = x, q = n;
      if (a[x] - 1 - i <= n)
        cout << a[x] - 1 - i << " ";
      else {
        while (a[p] - 1 - i > q) {
          q = a[p] - 2 - q;
          while (a[p] / 2 > q) {
            p--;
          }
        }
        cout << a[p] - 1 - i << " ";
      }
    }
  }
}
