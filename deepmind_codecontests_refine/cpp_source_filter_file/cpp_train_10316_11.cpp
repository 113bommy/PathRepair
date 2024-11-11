#include <bits/stdc++.h>
using namespace std;
long long int C[5005][5005];
long long int MOD(long long int a, long long int b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
int max3(int a, int b, int c) { return max(c, max(a, b)); }
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int logg(long long int a) {
  long long int x = 0;
  while (a > 1) {
    x++;
    a /= 2;
  }
  return x;
}
int main() {
  int ans = 0;
  int n;
  cin >> n;
  string A;
  string B;
  cin >> A;
  cin >> B;
  for (int i = 0; i < n / 2; i++) {
    int dif = 0;
    int L[4];
    L[0] = A[i];
    L[1] = A[n - i - 1];
    L[2] = B[n - i - 1];
    L[3] = B[i];
    sort(L, L + 4);
    for (int i = 0; i < 3; i++) {
      if (L[i] != L[i + 1]) {
        dif++;
      }
    }
    if (dif == 3) {
      ans = ans + 2;
    } else {
      if (dif == 2) {
        if (A[i] == A[n - i - 1]) {
          ans = ans + 2;
        } else {
          ans = ans + 1;
        }
      } else {
        if (dif == 1) {
          if (L[0] == L[1] && L[1] == L[2]) {
            ans = ans + 1;
          } else {
            if (L[1] == L[2] && L[2] == L[3]) {
              ans = ans + 1;
            } else {
              ans = ans;
            }
          }
        }
      }
    }
  }
  if (n % 2 != 0) {
    if (A[n / 2 + 1] != B[n / 2 + 1]) {
      ans++;
    }
  }
  cout << ans;
}
