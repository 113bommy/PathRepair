#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int z[3000000];
int acum[3000000];
int sol[3000000];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> s;
  {
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R - L] == s[R]) R++;
        z[i] = R - L;
        R--;
      } else {
        int k = i - L;
        if (z[k] < R - i + 1)
          z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R - L] == s[R]) R++;
          z[i] = R - L;
          R--;
        }
      }
    }
  }
  for (int i = 1; k * i <= n; i++) {
    bool error = false;
    for (int j = i, d = 1; d < k and not error; j += k, d++) error = z[j] < i;
    if (not error) {
      acum[k * i - 1]++;
      acum[k * i - 1 + min(i, z[k * i]) + 1]--;
    }
  }
  int suma = 0;
  for (int i = 0; i < n; i++) {
    suma += acum[i];
    cout << (suma > 0);
  }
  cout << endl;
}
