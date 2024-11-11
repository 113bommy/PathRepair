#include <bits/stdc++.h>
using namespace std;
long long cc = 10e9 + 7;
void Zarr(string s, long long Z[]) {
  long long n = s.size();
  if (n > 0) Z[0] = 0;
  long long L = 0, R = 0;
  for (long long i = 1; i < n; i++) {
    if (R < i) {
      L = i;
      R = i;
      while (R < n && s[R - L] == s[R]) R++;
      Z[i] = R - L;
      R--;
    } else {
      if (Z[i - L] < R - i + 1) {
        Z[i] = Z[i - L];
      } else {
        L = i;
        while (R < n && s[R - L] == s[R]) R++;
        Z[i] = R - L;
        R--;
      }
    }
  }
}
long long KK[100005];
long long KA[100005];
long long KL[100005];
long long Z[1000000];
int main() {
  string s, t, S;
  cin >> s >> t;
  S = t + s;
  Zarr(S, Z);
  long long nn = s.size();
  long long n = t.size();
  long long K[nn];
  memset(K, 0, sizeof(K));
  long long j = 0;
  for (long long i = n; i < S.size(); i++) {
    if (Z[i] >= n) K[j] = 1;
    j++;
  }
  for (long long i = nn - 1; i >= 0; i--) {
    if (K[i] == 0) {
      if (i < nn - 1) KK[i] = KK[i + 1];
    } else {
      KK[i] = (nn - i + 1 - n);
      if (i + n < nn) KK[i] = (KK[i] + KL[i + n]) % cc;
    }
    if (i < nn - 1)
      KA[i] = (KA[i + 1] + KK[i]) % cc;
    else
      KA[i] = KK[i];
    if (i < nn - 1)
      KL[i] = (KL[i + 1] + KA[i]) % cc;
    else
      KL[i] = KA[i];
  }
  cout << KA[0] << endl;
}
