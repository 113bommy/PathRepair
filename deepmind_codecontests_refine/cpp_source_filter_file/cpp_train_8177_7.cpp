#include <bits/stdc++.h>
using namespace std;
bitset<2011> a[2011];
int A[500011], B[500011], n, m;
void Gauss() {
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = i; j < n; j++)
      if (a[j][i]) {
        k = j;
        break;
      }
    swap(a[i], a[k]);
    for (int j = 0; j < n; j++) {
      if (j != i && a[j][i]) {
        a[j] ^= a[i];
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &A[i], &B[i]);
    A[i]--, B[i]--;
    a[A[i]][B[i]] = 1;
  }
  for (int i = 0; i < n; i++) a[i][i + n] = 1;
  Gauss();
  for (int i = 1; i <= m; i++) {
    if (a[B[i]][A[i] + n])
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
