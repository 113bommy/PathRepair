#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 1000 + 10;
string s;
char d[maxn];
long long a, b, mu[maxn], x, y;
int n, m, k;
int main() {
  std::ios::sync_with_stdio(false);
  k = -1;
  cin >> s;
  cin >> a >> b;
  n = s.size();
  for (int i = (1); i <= (n); i++) d[i] = s[i - 1];
  mu[0] = 1;
  for (int i = (1); i <= (n); i++) mu[i] = (mu[i - 1] * 10) % b;
  for (int i = 0; i < (s.size()); i++) y = (y * 10 + s[i] - '0') % b;
  for (int i = (1); i <= (n - 1); i++) {
    y = (((y - (d[i] - '0') * mu[n - i]) % b) + b) % b;
    x = (x * 10 + (d[i] - '0')) % a;
    if (d[i + 1] == '0') continue;
    if ((x == y) && (y == 0)) {
      k = i;
      break;
    }
  }
  if (k == -1) {
    cout << "NO" << endl;
    return 0;
  }
  printf("YES\n");
  for (int i = (1); i <= (k); i++) printf("%c", d[i]);
  printf("\n");
  for (int i = (k + 1); i <= (n); i++) printf("%c", d[i]);
  return 0;
}
