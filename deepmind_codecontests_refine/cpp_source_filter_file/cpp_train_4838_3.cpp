#include <bits/stdc++.h>
using namespace std;
const int rozmiar_kubelka = 356;
const int N = (1 << 19);
const long long mod = 1000000009;
string glowny, podrzedny;
long long hashh[N], hasz = 0;
long long xix[N];
long long xx = 2352434521;
void prepp() {
  xix[0] = 1;
  for (int i = 1; i <= N; i++) {
    xix[i] = xx * xix[i - 1];
  }
  for (int i = glowny.size() - 1; i >= 0; i--) {
    hashh[i] = hashh[i + 1] * xx + (long long)glowny[i];
  }
  hasz = 0;
  for (int i = podrzedny.size(); i > 0; i--) {
    hasz = hasz * xx + (long long)podrzedny[i - 1];
  }
}
bool czy(int a) {
  int zz = podrzedny.size();
  if (a + 1 >= podrzedny.size()) {
    if (hashh[a - zz + 1] - xix[podrzedny.size()] * hashh[a + 1] == hasz)
      return true;
  }
  return false;
}
void dodaj(int a, long long brrr, vector<long long> &Ss) {
  int uu = N;
  a += uu / 2;
  while (a > 0) {
    Ss[a] = Ss[a] + brrr;
    Ss[a] %= mod;
    a /= 2;
  }
}
long long ile(int a, int bb, vector<long long> &Ss) {
  int uu = N;
  a += uu / 2;
  bb += uu / 2;
  long long wynik = 0;
  while (a <= bb) {
    if (a % 2 == 1) {
      wynik += Ss[a];
      wynik %= mod;
      a++;
    }
    if (bb % 2 == 0) {
      wynik += Ss[bb];
      wynik %= mod;
      bb--;
    }
    a /= 2;
    bb /= 2;
  }
  return wynik;
}
int main() {
  long long odpowiedz[N];
  vector<long long> S;
  S.resize(N);
  for (int i = 0; i < N; i++) {
    S[i] = 0;
    odpowiedz[i] = 0;
  }
  cin >> glowny >> podrzedny;
  prepp();
  int ostatni = -1;
  if (podrzedny.size() == 1 && glowny[0] == podrzedny[0]) {
    odpowiedz[0] = 1;
    ostatni = 0;
    dodaj(0, 1ll, S);
  }
  for (long long i = 1ll; i < glowny.size(); i++) {
    long long wyniczek = 0;
    if (czy(i)) {
      int zz = podrzedny.size();
      ostatni = i - zz + 1;
    }
    if (ostatni > -1) {
      if (ostatni > 0) {
        wyniczek += odpowiedz[ostatni - 1];
      }
      wyniczek += ostatni + 1;
    } else
      wyniczek = 0;
    wyniczek %= mod;
    odpowiedz[i] = (odpowiedz[i - 1] + ile(0, i - 1, S) + wyniczek) % mod;
    dodaj(i, wyniczek, S);
  }
  cout << S[1];
}
