#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string N;
  cin >> N;
  long long int digits = N.length();
  long long int num[digits];
  long long int n = 0;
  for (long long int i = digits - 1; i > -1; i--) {
    char c = N[i];
    n += (long long int)pow(10, digits - 1 - i) * (c - '0');
  }
  long long int ans = 1;
  for (long long int i = 0; i < digits; i++) {
    num[i] = n % 10;
    ans *= num[i];
    n /= 10;
  }
  long long int comp[digits + 1];
  fill(comp, comp + digits + 1, 0);
  comp[digits] = ans;
  if (digits == 1) {
    cout << num[0] << '\n';
    return 0;
  }
  long long int give = (long long int)pow(9, digits - 1);
  if (num[digits] != 1) give *= num[digits - 1] - 1;
  comp[digits - 1] = give;
  for (long long int i = 0; i < digits - 1; i++) {
    long long int a = 0;
    for (long long int j = 0; j < digits; j++)
      a += num[j] * (long long int)pow(10, j);
    if (num[i] != 9) {
      a -= (long long int)pow(10, i) * (10 + num[i] - 9);
    }
    digits = (long long int)(log(a) / log(10)) + 1;
    for (long long int j = 0; j < digits; j++) {
      num[j] = a % 10;
      a /= 10;
    }
    long long int aa = 1;
    for (long long int j = 0; j < digits; j++) aa *= num[j];
    comp[i] = aa;
  }
  for (long long int i : comp) give = max(give, i);
  cout << give << '\n';
}
