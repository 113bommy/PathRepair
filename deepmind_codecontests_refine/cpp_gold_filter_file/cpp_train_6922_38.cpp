#include <bits/stdc++.h>
using namespace std;
int A[100005], B[100005];
int main() {
  int na, nb, k, m, foo;
  scanf("%d%d%d%d", &na, &nb, &k, &m);
  for (int i = 1; i <= na; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 0; i < nb; i++) {
    scanf("%d", &B[i]);
  }
  if (B[nb - m] > A[k])
    puts("YES");
  else
    puts("NO");
}
