#include <bits/stdc++.h>
using namespace std;
const int N3 = 1e3 + 15;
const int N4 = 1e4 + 15;
const int N5 = 1e5 + 15;
const int N6 = 1e6 + 15;
const int N7 = 1e7 + 15;
const int N8 = 1e8 + 15;
const int N9 = 1e9 + 15;
const int INF = 1111;
const double pi = acos(-1.0);
int n, m;
char ch[101][101];
int digit[110], alpha[110], symbol[110];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> ch[i][j], digit[i] = alpha[i] = symbol[i] = INF;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      if (isdigit(ch[i][j]))
        digit[i] = min(digit[i], min(j - 1, m - j + 1));
      else if (isalpha(ch[i][j]))
        alpha[i] = min(alpha[i], min(j - 1, m - j + 1));
      else
        symbol[i] = min(symbol[i], min(j - 1, m - j + 1));
    }
  int ans = INF;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k <= n; ++k)
        if (i != j && j != k && i != k)
          ans = min(ans, digit[i] + alpha[j] + symbol[k]);
  cout << ans;
}
