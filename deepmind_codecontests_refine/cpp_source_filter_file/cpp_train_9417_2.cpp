#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 0.0000000001;
using namespace std;
int T[200005], W[1000005], L[1000005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> T[i];
    W[T[i]] = 1;
  }
  sort(T + 1, T + n + 1);
  int last = 0;
  for (int i = 1; i <= 1000000; i++) {
    L[i] = last;
    if (W[i]) last = i;
  }
  int wynik = 0;
  last = 1;
  for (int i = 1; i <= n; i++) {
    if (T[i] != last) {
      for (int j = 2 * T[i]; j <= 1000000; j += T[i]) {
        wynik = max(wynik, T[i] - (j - L[j]));
      }
    }
    last = T[i];
  }
  cout << wynik;
  return 0;
}
