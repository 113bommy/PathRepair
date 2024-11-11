#include <bits/stdc++.h>
using namespace std;
int m[11][100100], s[100100];
bool c[100100];
int main() {
  string line;
  int n, k, w;
  cin >> n >> k >> w;
  cin >> line;
  memset(c, 0, sizeof(c));
  for (int i = 0; i < n; i++) c[i] = (line[i] == '1');
  memset(m, 0, sizeof(m));
  memset(s, 0, sizeof(s));
  for (int i = 0; i < 11; i++) {
    int j = 1;
    m[i][i] = 0;
    while (i + j <= n + 20) {
      if (j % k == 0) {
        m[i][i + j] = m[i][i + j - 1] + (c[i + j - 1] ? 1 : 0);
      } else
        m[i][i + j] = m[i][i + j - 1];
      j++;
    }
  }
  s[0] = 0;
  for (int i = 1; i <= n + 1; i++) {
    s[i] = s[i - 1] + (c[i - 1] ? 1 : 0);
  }
  for (int i = 0; i < w; i++) {
    int a, b, d;
    cin >> a >> b;
    d = (a - 1) % (k);
    int res = m[d][b] - m[d][a - 1];
    int aux = s[b] - s[a - 1] - res;
    cout << ((b - a + 1) / k) - res + aux << endl;
  }
  return 0;
}
