#include <bits/stdc++.h>
using namespace std;
int q, n, o, z, f;
char ch[100000];
int sum[100000];
int main() {
  cin >> q;
  while (q--) {
    f = -1;
    o = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) sum[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> ch[i];
      sum[i] = sum[i - 1] + ch[i] - '0';
      if ((ch[i] - '0') % 2 == 1) {
        o = f;
        f = i;
      }
    }
    if (f == -1 || (sum[f] % 2 == 1 && o == 0))
      cout << -1 << endl;
    else {
      if (sum[f] % 2 == 1) ch[o] = ' ';
      for (int i = 1; i <= f; i++)
        if (ch[i] != ' ') cout << ch[i];
      cout << endl;
    }
  }
}
