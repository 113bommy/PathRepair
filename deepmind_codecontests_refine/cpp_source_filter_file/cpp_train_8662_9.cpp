#include <bits/stdc++.h>
using namespace std;
int n;
int tabela[200][200][200][3];
vector<int> v;
int dp(int i, int par, int impar, int last) {
  int res = 1e8, tmp;
  if (i >= n) {
    return 0;
  }
  if (v[i] != 0) {
    if (v[i] % 2 == 0 and last == 1) {
      tmp = 1 + dp(i + 1, par, impar, 0);
    } else if (v[i] % 2 == 1 and last == 0) {
      tmp = 1 + dp(i + 1, par, impar, 1);
    } else {
      tmp = dp(i + 1, par, impar, v[i] % 2);
    }
    return tabela[i][par][impar][last] = tmp;
  }
  if (tabela[i][par][impar][last] != -1) return tabela[i][par][impar][last];
  if (par) {
    tmp = dp(i + 1, par - 1, impar, 0);
    if (last == 1) {
      tmp++;
    }
    res = min(res, tmp);
  }
  if (impar) {
    tmp = dp(i + 1, par, impar - 1, 0);
    if (last == 0) {
      tmp++;
    }
    res = min(res, tmp);
  }
  return tabela[i][par][impar][last] = res;
}
int main() {
  cin >> n;
  memset(tabela, -1, sizeof(tabela));
  for (int i = 0; i < (int)(n); i++) {
    int tmp;
    cin >> tmp;
    v.push_back(tmp);
  }
  vector<int> vals(n + 10, 0);
  for (int i = 0; i < (int)(n); i++) {
    vals[v[i]]++;
  }
  vector<int> pecas;
  int par = 0, impar = 0;
  for (int i = 1; i <= (int)(n); i++) {
    if (!vals[i]) {
      if (i % 2) {
        impar++;
      } else {
        par++;
      }
    }
  }
  if (n == 1) {
    cout << "0"
         << "\n";
    ;
    return 0;
  }
  if (par + impar == n) {
    cout << "1"
         << "\n";
    ;
    return 0;
  }
  cout << min(dp(0, par, impar, 1), dp(0, par, impar, 0)) << "\n";
  ;
  return 0;
}
