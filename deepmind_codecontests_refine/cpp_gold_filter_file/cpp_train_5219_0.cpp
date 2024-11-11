#include <bits/stdc++.h>
using namespace std;
int cores[300005];
vector<int> grafo[300005];
bool possivel = true;
long long int op1, op2;
void colore(int a, int cor) {
  if (cor)
    op1++;
  else
    op2++;
  cores[a] = cor;
  for (int i = 0; i < grafo[a].size(); i++) {
    int filho = grafo[a][i];
    if (cores[filho] == cores[a]) {
      possivel = false;
      return;
    }
    if (cores[filho] == -1) {
      colore(filho, (cor xor 1));
    }
  }
}
long int exponentiation(long long int base, long long int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base % 998244353;
  long long int t = exponentiation(base, exp / 2);
  t = (t * t) % 998244353;
  if (exp % 2 == 0)
    return t;
  else
    return ((base % 998244353) * t) % 998244353;
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  int t;
  cin >> t;
  while (t > 0) {
    int n, m;
    cin >> n >> m;
    possivel = true;
    for (int i = 0; i < n + 1; i++) {
      cores[i] = -1;
    }
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      grafo[a].push_back(b);
      grafo[b].push_back(a);
    }
    long long int res = 0;
    for (int i = 1; i <= n; i++) {
      long long int res1 = 0, res2 = 0;
      op1 = 0;
      op2 = 0;
      if (cores[i] == -1) {
        colore(i, 0);
        res1 = exponentiation(2LL, op1);
        res2 = exponentiation(2LL, op2);
        if (res == 0)
          res = (res1 % 998244353 + res2 % 998244353) % 998244353;
        else
          res = (res % 998244353 * (res1 % 998244353 + res2 % 998244353)) %
                998244353;
      }
    }
    if (possivel)
      cout << res % 998244353 << endl;
    else
      cout << 0 << endl;
    for (int i = 0; i < n + 1; i++) {
      grafo[i].clear();
    }
    t--;
  }
}
