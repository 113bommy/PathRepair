#include <bits/stdc++.h>
using namespace std;
int k;
string a, b;
long long res, aux, x, y;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> k;
  res = (a == b);
  aux = (res) ? (0) : (1);
  for (int i = 0; i < (int)((int)(b).size()); i++) {
    char c = a.back();
    a.pop_back();
    a = c + a;
    if (a == b)
      x++;
    else
      y++;
  }
  for (int i = 1; i <= (int)k; i++) {
    long long R = res, A = aux;
    res = (R * (x - 1) + A * x) % 1000000007;
    aux = (R * y + A * (y - 1)) % 1000000007;
  }
  cout << res;
}
