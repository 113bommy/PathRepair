#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int cont[MAXN];
int main() {
  int n, x, y, res;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x >> y;
    res = 0;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0 && j * j != x) {
        if (!cont[j] || !y) {
          cont[j] = i;
          res++;
        } else if (cont[j] < i && cont[j] >= i - y) {
          cont[j] = i;
        } else {
          res++;
          cont[j] = i;
        }
        if (!cont[x / j] || !y) {
          cont[x / j] = i;
          res++;
        } else if (cont[x / j] < i && cont[j] >= i - y) {
          cont[x / j] = i;
        } else {
          res++;
          cont[x / j] = i;
        }
      } else if (j * j == x && x % j == 0) {
        if (!cont[j] || !y) {
          cont[j] = i;
          res++;
        } else if (cont[j] < i && cont[j] >= i - y) {
          cont[x / j] = i;
        } else {
          res++;
          cont[x / j] = i;
        }
      }
    }
    cout << res << endl;
  }
}
