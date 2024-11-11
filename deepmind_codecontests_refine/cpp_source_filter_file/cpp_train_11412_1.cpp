#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
inline int ifnotzero(int num) { return ~((num - 1) >> 31); }
int Q, t, L, R, k;
int data[100005][2];
int main() {
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d%d", &L, &R, &k);
      bool idx = k > 0;
      uint32_t dt = abs(k) - 1;
      for (int i = L; i < R; ++i) {
        uint32_t a = data[i][idx] - 1;
        data[i][idx] = (a < dt ? a : dt) + 1;
      }
    } else {
      scanf("%d%d", &L, &R);
      long long res = 0;
      for (int i = L; i < R; ++i)
        res += (data[i][0] + data[i][1]) & ifnotzero(data[i][1]) &
               ifnotzero(data[i][1]);
      cout << res << endl;
    }
  }
}
