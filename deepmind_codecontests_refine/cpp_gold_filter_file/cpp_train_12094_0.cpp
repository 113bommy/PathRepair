#include <bits/stdc++.h>
using namespace std;
int divs[1000];
bool even[200001];
int cmmdc(int a, int b) {
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int n, i, nr = 1, j, k;
  string s;
  cin >> n >> s;
  divs[1] = 1;
  for (i = 2; i * i < n; ++i) {
    if (n % i == 0) {
      divs[++nr] = i;
      divs[++nr] = n / i;
    }
  }
  if (i * i == n) {
    divs[++nr] = i;
  }
  for (i = 1; i <= nr; ++i) {
    for (j = 0; j < divs[i]; ++j) {
      k = j;
      int sum = 0;
      while (k < n) {
        sum += (s[k] - '0');
        k += divs[i];
      }
      if (sum % 2) {
        break;
      }
    }
    if (j == divs[i]) {
      even[divs[i]] = true;
    }
  }
  for (i = 0; i < n; ++i) {
    if (s[i] == '1') {
      break;
    }
  }
  if (i == n) {
    even[n] = true;
  }
  int sol = 0;
  for (i = 0; i < n; ++i) {
    int d = cmmdc(i, n);
    sol += even[d];
  }
  cout << sol << endl;
  return 0;
}
