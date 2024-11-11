#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5 + 23;
long double big[MM], sm[MM];
long double mini[MM], maxi[MM];
long double sqrtx(long double f) {
  if (f < 0.00000000001) {
    return 1;
  }
  return sqrtl(f);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> maxi[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> mini[i];
  }
  long double cmax = 0, cmin = 0;
  for (int i = 0; i < N; i++) {
    cmax += maxi[i];
    cmin += mini[i];
    long double alf = cmax;
    long double bet = cmin + cmax;
    long double det = sqrtx(bet * bet - 4 * alf);
    sm[i] = (bet - det) / 2.0;
    big[i] = (bet + det) / 2.0;
  }
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      cout << fixed << setprecision(8) << sm[i] << " ";
    } else {
      cout << fixed << setprecision(8) << sm[i] - sm[i - 1] << " ";
    }
  }
  cout << '\n';
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      cout << fixed << setprecision(8) << big[i] << " ";
    } else {
      cout << fixed << setprecision(8) << big[i] - big[i - 1] << " ";
    }
  }
  return 0;
}
