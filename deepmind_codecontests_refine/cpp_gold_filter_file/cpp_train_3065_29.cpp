#include <bits/stdc++.h>
using namespace std;
set<int> A[100009];
int sak[1009];
int B[100009];
int main() {
  int n, m, s, e, t;
  while (scanf("%d %d %d %d", &n, &m, &s, &e) == 4) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &B[i]);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", &t);
      A[t].insert(i);
    }
    int res = 0, outp = 0;
    for (int i = 0; i < n; i++) {
      if (A[B[i]].size() != 0) {
        if (res == 0) {
          sak[0] = *(A[B[i]].begin());
          res++;
          if (outp < res && e * res + i + 1 + sak[res - 1] + 1 <= s) {
            outp = res;
          }
        } else {
          for (int j = res - 1; j >= 0; j--) {
            set<int>::iterator it = A[B[i]].upper_bound(sak[j]);
            if (it != A[B[i]].end()) {
              if (j == res - 1) {
                if (e * (res + 1) < s) {
                  sak[j + 1] = *it;
                  res++;
                  if (outp < res && e * res + i + 1 + sak[res - 1] + 1 <= s) {
                    outp = res;
                  }
                }
              } else if (*it < sak[j + 1]) {
                sak[j + 1] = *it;
                if (outp < j + 2 && e * (j + 2) + i + 1 + sak[j + 1] + 1 <= s) {
                  outp = j + 2;
                }
              }
            }
          }
          set<int>::iterator it = A[B[i]].begin();
          if (it != A[B[i]].end()) {
            if (*it < sak[0]) {
              sak[0] = *it;
              if (outp < 1 && e * 1 + i + 1 + sak[0] + 1 <= s) {
                outp = 1;
              }
            }
          }
        }
      }
    }
    printf("%d\n", outp);
  }
  return 0;
}
