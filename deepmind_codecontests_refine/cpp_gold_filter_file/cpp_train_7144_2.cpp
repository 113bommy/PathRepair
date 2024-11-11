#include <bits/stdc++.h>
using namespace std;
int f[100010], h[100010], s[100010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; (1 + j) * j / 2 <= i; j++)
      if ((i * 2 - j * j + j) % (j * 2) == 0) {
        int a0 = (i * 2 - j * j + j) / (j * 2);
        h[s[a0 + j - 1] ^ s[a0 - 1]] = i;
      }
    while (h[f[i]] == i) f[i]++;
    s[i] = s[i - 1] ^ f[i];
  }
  if (!f[n])
    cout << -1 << endl;
  else {
    for (int j = 2; (1 + j) * j / 2 <= n; j++)
      if ((n * 2 - j * j + j) % (j * 2) == 0) {
        int a0 = (n * 2 - j * j + j) / (j * 2);
        if ((s[a0 + j - 1] ^ s[a0 - 1]) == 0) {
          cout << j << endl;
          break;
        }
      }
  }
}
