#include <bits/stdc++.h>
long long v[100000][2];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &v[j][i]);
    }
  }
  long long topB = 2000000001;
  long long botB = 0;
  long long t = (topB + botB) / 2;
  long long finalK = (long long)k;
  while (1 == 1) {
    long long temporaryK = 0;
    for (int i = 0; i < n; i++) {
      long long p = t * (long long)(v[i][0]) - v[i][1];
      if (p > 0) temporaryK += p;
      if (temporaryK > finalK) break;
    }
    if (temporaryK > finalK) {
      topB = t;
    } else {
      botB = t;
    }
    t = (topB + botB) / 2;
    if (topB == botB + 1) break;
  }
  std::cout << t << std::endl;
  return 0;
}
