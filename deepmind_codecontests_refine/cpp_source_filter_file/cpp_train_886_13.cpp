#include <bits/stdc++.h>
using namespace std;
int ar[5010][5010];
int ar3[5010];
int ar4[5010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &ar3[i]);
  for (int i = 1; i <= n; i++) {
    ar4[ar3[i]]++;
    ar[i][ar3[i]]++;
    int mx = ar3[i];
    for (int j = i + 1; j <= n; j++) {
      ar[i][ar3[j]]++;
      if ((ar[i][ar3[j]] == ar[i][mx] && ar3[j] < mx) ||
          ar[i][ar3[j]] > ar[i][mx]) {
        mx = ar3[j];
        ar4[ar3[j]]++;
      } else
        ar4[ar3[mx]]++;
    }
  }
  printf("%d", ar4[1]);
  for (int i = 2; i <= n; i++) printf(" %d", ar4[i]);
  printf("\n");
  return 0;
}
