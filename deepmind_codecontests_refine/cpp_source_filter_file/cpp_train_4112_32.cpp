#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int liczba = n;
  int dlugosc = 0;
  while (liczba) {
    dlugosc++;
    liczba /= 10;
  }
  long long wynik = dlugosc * (n + 1);
  long long p10 = 1;
  for (int i = 0; i < dlugosc; i++) {
    wynik -= p10;
    p10 *= 10;
  }
  cout << wynik << "\n";
  return 0;
}
