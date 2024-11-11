#include <bits/stdc++.h>
using namespace std;
char Map[5505][5505];
int prime[11000] = {0}, num_prime = 0;
int isNotPrime[5000] = {1, 1};
int main() {
  for (int i = 2; i < 5000; i++) {
    if (!isNotPrime[i]) {
      prime[num_prime++] = i;
    }
    for (int j = 0; j < num_prime && i * prime[j] < 5000; j++) {
      isNotPrime[i * prime[j]] = 1;
      if (!(i % prime[j])) {
        break;
      }
    }
  }
  int n, m, i, j, k, l, o;
  scanf("%d%d", &n, &m);
  memset(Map, 0, sizeof(Map));
  int aa = 0, bb = 0;
  for (i = 0; i < n; i++) {
    getchar();
    for (j = 0; j < m; j++) {
      scanf("%c", &Map[i][j]);
      if (Map[i][j] == '0') {
        aa++;
      } else {
        bb++;
      }
    }
  }
  int Min = min(aa, bb);
  for (i = 0; i <= 2500; i++) {
    if (i >= n && i >= m) break;
    if (!isNotPrime[i]) {
      int aa = 0, bb = 0, cc = 0, dd = 0, ss = 0;
      aa = (int)ceil(1.0 * n / i);
      bb = (int)ceil(1.0 * m / i);
      for (j = 0; j < aa; j++) {
        for (k = 0; k < bb; k++) {
          cc = 0;
          dd = 0;
          for (l = 0; l < i; l++) {
            for (o = 0; o < i; o++) {
              if (Map[l + j * i][o + k * i] == '0' ||
                  Map[l + j * i][o + k * i] == 0)
                cc++;
              else
                dd++;
            }
          }
          ss += min(cc, dd);
        }
      }
      if (m > 300) {
        if (ss > Min) break;
      }
      Min = min(Min, ss);
    }
  }
  printf("%d\n", Min);
  return 0;
}
