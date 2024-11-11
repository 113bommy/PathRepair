#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], n, m, i, j, t, g;
char o[100005], c;
int main() {
  cin >> n >> m;
  for (i = 2; i <= n; ++i)
    if (!a[i])
      for (j = i; j <= n; j += i) a[j] = i;
  while (m--) {
    cin >> c >> i;
    if (c == '+') {
      if (o[i]) {
        cout << "Already on" << endl;
        continue;
      }
      g = 1;
      for (j = i; j > 1;) {
        t = a[j];
        if (b[t]) {
          cout << "Conflict with " << b[t] << endl;
          g = 0;
          break;
        }
        do {
          j /= t;
        } while (j % t == 0);
      }
      if (g) {
        cout << "Success" << endl;
        o[i] = 1;
        for (j = i; j > 1;) {
          b[t = a[j]] = i;
          do {
            j /= t;
          } while (j % t == 0);
        }
      }
    } else {
      if (!o[i]) {
        cout << "Already off" << endl;
        continue;
      }
      for (j = i; j > 1;) {
        b[t = a[j]] = 0;
        do {
          j /= t;
        } while (j % t == 0);
      }
      o[i] = 0;
      cout << "Success" << endl;
    }
  }
}
