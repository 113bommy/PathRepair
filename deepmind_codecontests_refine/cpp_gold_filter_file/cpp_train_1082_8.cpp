#include <bits/stdc++.h>
using namespace std;
const int SIZE = 100009;
long long int hs[SIZE], ps[SIZE];
int N, M;
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%I64d", hs + i);
  for (int i = 0; i < M; i++) scanf("%I64d", ps + i);
  long long int l = -1, r = 30000000000ll;
  while (l + 1 < r) {
    long long int m = (l + r) >> 1;
    bool check = true;
    for (int i = 0, j = 0; check && i < M;)
      if (j >= N)
        check = false;
      else if (hs[j] <= ps[i]) {
        while (i < M && hs[j] + m >= ps[i]) i++;
        j++;
      } else if (hs[j] - m > ps[i])
        j++;
      else {
        long long int d;
        if ((m - (hs[j] - ps[i])) / 2 < hs[j] - ps[i])
          d = (m - (hs[j] - ps[i])) / 2;
        else
          d = m - 2 * (hs[j] - ps[i]);
        while (i < M && ps[i] <= hs[j] + d) i++;
        j++;
      }
    if (check)
      r = m;
    else
      l = m;
  }
  printf("%I64d\n", r);
  return 0;
}
