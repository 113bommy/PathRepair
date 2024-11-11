#include <bits/stdc++.h>
using namespace std;
long long A[200000] = {-1, 6, -1, 2, -1, 4, 7, -1, 2};
int main() {
  int T = 9;
  scanf("%d", &T);
  long long cnt = 1, last_v = 0, last_i = 0, d = 0, res = 0, l = 0;
  for (int i = 0; i < T; i++) {
    scanf("%d", &A[i]);
    if (cnt == 1) {
      if (A[i] != -1) {
        cnt++;
        last_v = A[i];
        last_i = i;
      }
    } else if (cnt == 2) {
      if (A[i] != -1) {
        if ((A[i] - last_v) % (i - last_i)) {
          l = i;
          cnt = 2;
          res++;
        } else {
          d = (A[i] - last_v) / (i - last_i);
          if ((l - i) * d + A[i] <= 0) {
            cnt = 2;
            l = i;
            res++;
          } else {
            cnt++;
          }
        }
        last_v = A[i];
        last_i = i;
      }
    } else {
      if (A[i] == -1) {
        if (last_v + d <= 0) {
          cnt = 1;
          res++;
          l = i;
        } else {
          last_v += d;
          last_i = i;
        }
      } else {
        if (last_v + d != A[i]) {
          cnt = 2;
          res++;
          l = i;
          last_v = A[i];
          last_i = i;
        } else {
          last_v += d;
          last_i = i;
        }
      }
    }
  }
  res++;
  printf("%d\n", res);
  return 0;
}
