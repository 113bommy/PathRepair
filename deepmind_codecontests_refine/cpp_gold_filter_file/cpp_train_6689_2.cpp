#include <bits/stdc++.h>
using namespace std;
int winner_normal(long long e, long long s) {
  if (e % 2 == 0) return s % 2;
  long long tres = (e - 1) / 2LL;
  if (s > tres) return (s % 2) ^ 1;
  if (s >= (tres + 2) / 2) return 0;
  return winner_normal((tres + 2) / 2, s);
}
int winner_misere(long long e, long long s) {
  long long autowin = (e + 1LL) / 2LL;
  if (s >= autowin) return 0;
  if (autowin % 2 == 0) return s % 2;
  long long uwu = (autowin - 1) / 2;
  if (s <= uwu) return winner_misere(uwu + 1, s);
  return (s % 2) ^ 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int guar = 1;
  int n;
  cin >> n;
  while (n--) {
    long long s, e;
    cin >> s >> e;
    e++;
    int tmp = 0;
    long long nm = winner_normal(e, s), ms = winner_misere(e, s);
    if (guar & 1) {
      if (nm == 0) tmp |= 2;
      if (ms == 0) tmp |= 1;
    }
    if (guar & 2) {
      if (nm == 1) tmp |= 2;
      if (ms == 1) tmp |= 1;
    }
    guar = tmp;
  }
  cout << (guar & 2) / 2 << " " << (guar & 1) << '\n';
}
