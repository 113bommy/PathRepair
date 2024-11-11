#include <bits/stdc++.h>
using namespace std;
const long long nr = 7010;
const long long mr = 1e5 + 100;
inline long long read() {
  long long ret = 0;
  long long x = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') x = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = ret * 10 + ch - '0';
    ch = getchar();
  }
  return ret * x;
}
bitset<nr> a[mr];
bitset<nr> u[mr];
bitset<nr> basic[mr];
long long prime[nr];
long long mu[nr];
bool mark[nr];
void GetPrime(long long top) {
  mu[1] = 1;
  for (int i = 2; i <= top; i++) {
    if (!mark[i]) {
      prime[++prime[0]] = i;
      mu[i] = -1;
    }
    for (int j = 1; j <= prime[0]; j++) {
      if (i * prime[j] > top) break;
      mark[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        mu[i * prime[j]] = 0;
        break;
      }
      mu[i * prime[j]] = -mu[i];
    }
  }
}
int main() {
  GetPrime(nr - 1);
  for (int i = 1; i <= nr - 1; i++) {
    for (int j = i; j <= nr - 1; j += i) {
      basic[j][i] = 1;
      u[i][j] = (mu[j / i] + 2) % 2;
    }
  }
  long long n, Q;
  n = read();
  Q = read();
  for (int ti = 1; ti <= Q; ti++) {
    long long opt, x, y, z;
    opt = read();
    if (opt == 1) {
      x = read();
      y = read();
      a[x] = basic[y];
    }
    if (opt == 2) {
      x = read();
      y = read();
      z = read();
      a[x] = a[y] ^ a[z];
    }
    if (opt == 3) {
      x = read();
      y = read();
      z = read();
      a[x] = a[y] & a[z];
    }
    if (opt == 4) {
      x = read();
      y = read();
      cout << (a[x] & u[y]).count();
    }
  }
  return 0;
}
