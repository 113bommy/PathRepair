#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> v(n + b, 0);
  int ct;
  cin >> ct;
  map<int, int> mapa;
  for (int q = 1; q <= ct; q++) {
    int op, k;
    cin >> op >> k;
    if (op == 1) {
      bool achou = false;
      for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
          int tam = k;
          if (i != 0) tam += a;
          if (i + tam + b < n) tam += b;
          if (i + tam > n) break;
          bool cabe = true;
          for (int j = i; j < i + tam; j++) {
            if (v[j] != 0) {
              cabe = false;
              i = j;
            }
          }
          if (cabe) {
            int st = i + ((i != 0) ? a : 0);
            cout << st << endl;
            mapa[q] = st;
            for (int j = st; j < st + k; j++) v[j] = q;
            achou = true;
            break;
          }
        }
      }
      if (!achou) cout << -1 << endl;
    } else {
      int i = mapa[k];
      while (v[i] == k) v[i++] = 0;
    }
  }
}
