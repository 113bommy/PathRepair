#include <bits/stdc++.h>
using namespace std;
char f[4][1000001];
int c[8], best = 0x7f7f7f7f;
int main(int argc, char *argv[]) {
  int a[6], b[6], q[6] = {1, 1, 1, -1, -1, -1}, p[6] = {1, 2, 4, 3, 5, 6};
  for (int i = 0; i < (int)(6); i++) cin >> a[i];
  b[0] = a[0] + a[1] - a[4] - a[5];
  b[1] = a[0] - a[2] + a[3] - a[5];
  b[2] = a[1] - a[2] + a[3] - a[4];
  b[3] = a[4] + a[2] - a[0];
  b[4] = a[5] + a[2] - a[1];
  b[5] = a[5] + a[4] - a[3];
  for (int i = 0; i < (int)(6); i++) {
    if (b[i] % 2) {
      cout << "-1" << endl;
      return 0;
    } else
      b[i] /= 2;
  }
  for (int i = 0; i < (int)(100001); i++) {
    int sum = i, exitrep = 0;
    for (int j = 0; j < (int)(6); j++) {
      int dd = q[j] * i + b[j];
      if (dd < 0)
        exitrep = 1;
      else
        sum += dd;
    }
    if (exitrep) break;
    if (sum < best) {
      c[7] = i;
      best = sum;
    }
  }
  if (best == 0x7f7f7f7f)
    cout << -1 << endl;
  else {
    for (int i = 0; i < (int)(6); i++) c[p[i]] = q[i] * c[7] + b[i];
    int top = 0;
    for (int i = (int)(1); i < (int)(8); i++) {
      for (int j = 0; j < (int)(c[i]); j++) {
        for (int k = 0; k < (int)(4); k++) {
          f[k][top] = 'a' + ((i >> k) & 1);
        }
        top++;
      }
    }
    for (int i = 0; i < (int)(4); i++) f[i][top] = 0;
    printf("%d\n", best);
    for (int i = 0; i < (int)(4); i++) printf("%s\n", f[i]);
  }
  return EXIT_SUCCESS;
}
