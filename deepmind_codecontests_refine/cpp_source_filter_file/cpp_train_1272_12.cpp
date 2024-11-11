#include <bits/stdc++.h>
using namespace std;
int ba[100], j, ma = 0, reama = 0, idx = 0;
int main() {
  int T = 1;
  while (T--) {
    int N;
    scanf("%d", &N);
    vector<int> k;
    for (int i = 0; i < N; i++) {
      int a;
      scanf("%d", &a);
      k.push_back(a);
      for (j = 0; a; j++) {
        ba[j] += a % 2;
        a /= 2;
      }
      ma = max(j, ma);
    }
    ma += 1;
    for (int i = 0; i < N; i++) {
      int ck[100];
      int as = k[i];
      for (j = 0; as; j++) {
        ck[j] = as % 2;
        as /= 2;
      }
      int bin = 1, hab = 0;
      for (j = 0; j < ma; j++) {
        if (ba[j] == ck[j] && ba[j] == 1) {
          hab += bin;
        }
        bin *= 2;
      }
      if (reama < hab) {
        idx = i;
        reama = hab;
      }
    }
    printf("%d ", k[idx]);
    for (int i = 0; i < N; i++) {
      if (idx == i) continue;
      printf("%d ", k[i]);
    }
  }
  return 0;
}
