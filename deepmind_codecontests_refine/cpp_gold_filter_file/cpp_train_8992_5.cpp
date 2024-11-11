#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 1001001;
int tab[N];
long long sil[N];
long long odwS[N];
long long I[N];
int n;
long long pot(long long a, int wyk) {
  long long res = 1;
  while (wyk) {
    if (wyk & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    wyk >>= 1;
  }
  return res;
}
long long odw(long long a) { return pot(a, mod - 2); }
int main() {
  scanf("%d", &n);
  sil[0] = 1;
  odwS[0] = 1;
  for (int i = 1; i <= (n); ++i) {
    sil[i] = (sil[i - 1] * i) % mod;
    odwS[i] = odw(sil[i]);
  }
  int res = 0;
  int l1 = 0, l2 = 0;
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &tab[i]);
    if (tab[i] == 1) l1++;
    if (tab[i] == 2) l2++;
  }
  I[1] = I[0] = 1;
  for (int i = 2; i <= (l1); ++i) I[i] = (I[i - 1] + (i - 1) * I[i - 2]) % mod;
  cout << (((sil[n] * odwS[l1]) % mod) * I[l1]) % mod << endl;
}
