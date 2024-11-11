#include <bits/stdc++.h>
using namespace std;
const long long int modulo = 1e9 + 7;
long long int eleva(long long int b, long long int e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return eleva(b * b % modulo, e / 2);
  return b * eleva(b * b % modulo, e / 2) % modulo;
}
long long int inverso(long long int x) { return eleva(x, modulo - 2); }
void anyade(int &a, long long int b) { a = (a + b) % modulo; }
const int limite = 5005;
long long int sq(long long int x) { return x * x % modulo; }
int n;
long long int a[limite];
long long int pa[limite];
long long int painv[limite];
long long int paentre(int l, int r) { return pa[r] * painv[l - 1] % modulo; }
int maner[limite][2 * limite];
int sol[2 * limite];
long long int inv2;
int main() {
  inv2 = inverso(2);
  cin >> n;
  pa[0] = 1;
  painv[0] = 1;
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    pa[i] = pa[i - 1] * a[i] % modulo;
    painv[i] = inverso(pa[i]);
  }
  maner[n][0] = 1;
  for (int i = n - 1; i >= 1; i--) {
    maner[i][0] = 1;
    for (int k = 2; k <= 2 * (n - i); k++)
      anyade(maner[i][k], maner[i + 1][k - 2] * sq(a[i]));
    for (int k = 1; k <= n - i; k++)
      anyade(maner[i][k], 2 * paentre(i, i + k - 1));
    for (int k = 2; k <= 2 * (n - i); k++)
      anyade(sol[k], paentre(1, i - 1) * maner[i + 1][k - 2] % modulo * a[i] %
                         modulo * (a[i] - 1) % modulo * inv2);
    for (int k = 1; k <= n - i; k++)
      anyade(sol[k], paentre(1, i - 1) * paentre(i, i + k - 1));
  }
  for (int k = 1; k <= 2 * n - 2; k++) {
    if (k > 1) cout << " ";
    cout << sol[k];
  }
  cout << endl;
}
