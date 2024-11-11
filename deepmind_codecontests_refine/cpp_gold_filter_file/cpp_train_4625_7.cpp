#include <bits/stdc++.h>
using namespace std;
const int N = 1000006, M = 1 << 20;
int A[M], m, tab[M], S, d[2 * M + 5];
void wstaw(int pos, int ile) {
  pos += M;
  d[pos] = ile;
  pos /= 2;
  while (pos > 0) {
    d[pos] = d[2 * pos] + d[2 * pos + 1];
    pos /= 2;
  }
  return;
}
int zapytaj(int pos, int ile) {
  if (pos >= M) return pos - M;
  if (d[pos] < ile) return -1;
  if (d[2 * pos] >= ile) {
    pos *= 2;
  } else {
    ile -= d[2 * pos];
    pos = 2 * pos + 1;
  }
  return zapytaj(pos, ile);
}
void ujeb() {
  int ile_odjac = 0;
  for (int i = (1); i <= (m); ++i) {
    int a = zapytaj(1, A[i] - ile_odjac);
    if (a == -1) return;
    wstaw(a, 0);
    ile_odjac++;
  }
}
void wypisz() {
  vector<int> pozycje;
  for (int i = (1); i <= (S); ++i)
    if (d[i + M] > 0) pozycje.push_back(tab[i]);
  if (pozycje.empty()) {
    cout << "Poor stack!\n";
    return;
  }
  for (__typeof((pozycje).begin()) it = ((pozycje).begin());
       it != (pozycje).end(); ++it)
    cout << *it;
  cout << "\n";
}
void jebaj() {
  int n;
  cin >> n >> m;
  for (int i = (0); i <= ((m)-1); ++i) cin >> A[i + 1];
  for (int i = (0); i <= ((n)-1); ++i) {
    int a;
    cin >> a;
    if (a < 0) {
      ujeb();
    } else {
      S++;
      tab[S] = a;
      wstaw(S, 1);
    }
  }
  wypisz();
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  t = 1;
  for (int i = (0); i <= ((t)-1); ++i) {
    jebaj();
  }
}
