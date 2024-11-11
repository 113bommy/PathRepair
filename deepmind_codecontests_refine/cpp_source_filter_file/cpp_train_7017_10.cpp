#include <bits/stdc++.h>
using namespace std;
int const mxsz = 300009;
int beat[mxsz];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int ar[3];
    scanf("%d%d%d", ar, ar + 1, ar + 2);
    bool taken[3] = {1, 1, 1};
    for (int i = 0; i < 3; ++i)
      if (beat[ar[i]]) taken[beat[ar[i]] - 1] = 0;
    for (int i = 0; i < 3; ++i)
      if (!beat[ar[i]])
        for (int j = 0; j < 3; ++j) {
          if (taken[j]) {
            beat[ar[i]] = j + 1, taken[j] = 0;
            break;
          }
        }
  }
  for (int i = 1; i < n; ++i) printf("%d ", beat[i]);
}
