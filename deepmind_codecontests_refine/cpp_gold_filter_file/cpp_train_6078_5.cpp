#include <bits/stdc++.h>
using namespace std;
const long long MODULO = 1000 * 1000 * 1000 + 7;
long long n, k, wynik;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  wynik = 1;
  for (int i = 1; i < k; i++) wynik = (wynik * k) % MODULO;
  for (int i = 1; i <= n - k; i++) wynik = (wynik * (n - k)) % MODULO;
  cout << wynik % MODULO << "\n";
}
