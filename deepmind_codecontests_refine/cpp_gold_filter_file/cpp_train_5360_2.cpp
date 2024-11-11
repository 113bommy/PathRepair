#include <bits/stdc++.h>
using namespace std;
int N, nr[300], viz[300], ma, p[300], cnt, f[300];
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &f[i]);
  }
  for (int i = 1; i <= N; ++i) {
    int curr = i;
    for (int j = 1; j <= N; ++j) {
      viz[j] = 0;
      nr[j] = 0;
    }
    for (int j = 1; j <= N; ++j) {
      viz[curr] = 1;
      nr[curr] = j;
      curr = f[curr];
      if (viz[curr]) {
        if (curr == i) {
          p[++cnt] = j;
        } else {
          ma = max(ma, nr[curr] - 1);
        }
        break;
      }
    }
  }
  long long rez = 1;
  for (int i = 1; i <= cnt; ++i) {
    rez = lcm(rez, p[i]);
  }
  long long L = rez;
  while (L < ma) {
    L += rez;
  }
  cout << L;
  return 0;
}
