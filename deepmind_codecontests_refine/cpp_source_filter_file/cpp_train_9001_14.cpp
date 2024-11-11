#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1000 * 1000 + 5;
int gdzie[N];
int tab[N];
int main() {
  int n, q;
  long long B;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", tab + i);
  for (int i = 0; i < n; i++) tab[i + n] = tab[i];
  while (q--) {
    scanf("%lld", &B);
    long long ile = 0;
    int g = 0;
    for (int i = 0; i < 2 * n; i++) {
      while (g < 2 * n && ile + tab[g] <= B) {
        ile += tab[g];
        g++;
      }
      gdzie[i] = g;
      ile -= tab[i];
    }
    int wynik = 0;
    int mpoz = 0;
    int mile = gdzie[0];
    g = 0;
    while (g < n) {
      wynik++;
      if (gdzie[g] < n && mile > gdzie[g] - g) {
        mile = gdzie[g] - g;
        mpoz = g;
      }
      g = gdzie[g];
    }
    for (int i = max(0, mpoz - 1); i < n && i < mpoz + mile; i++) {
      int mwynik = 0;
      g = i;
      while (g < n + i) {
        mwynik++;
        g = gdzie[g];
      }
      wynik = min(wynik, mwynik);
    }
    printf("%d\n", wynik);
  }
}
