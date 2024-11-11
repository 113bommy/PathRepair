#include <bits/stdc++.h>
using namespace std;
char bn[1000010];
char nn[1000010];
long long c;
int main() {
  scanf("%s %s", bn, nn);
  cin >> c;
  int blen = strlen(bn);
  long long b = 0;
  for (int i = 0; i < blen; i++) {
    b *= 10;
    b += bn[i] - '0';
    b %= c;
  }
  int len = strlen(nn);
  int ind = len - 1;
  while (ind >= 0) {
    if (nn[ind] == '0') {
      nn[ind] = '9';
      ind--;
    } else {
      nn[ind]--;
      break;
    }
  }
  long long curr = b;
  long long res = 1;
  for (int i = len - 1; i >= 0; i--) {
    for (int j = 0; j < nn[i] - '0'; j++) {
      res = (res * curr) % c;
    }
    long long ncurr = 1;
    for (int j = 0; j < 10; j++) {
      ncurr *= curr;
      ncurr %= c;
    }
    curr = ncurr;
  }
  res *= b + c - 1;
  res %= c;
  if (res == 0) res = c;
  cout << res << endl;
  return 0;
}
