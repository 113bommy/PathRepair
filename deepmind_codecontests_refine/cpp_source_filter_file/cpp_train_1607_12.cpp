#include <bits/stdc++.h>
using namespace std;
int main() {
  int m1[3];
  for (int i = 0; i < 3; i++) scanf("%d", &m1[i]);
  int m2[3], ks = 0;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &m2[i]);
    if (m2[i] == m1[i]) ks++;
  }
  if (ks == 2)
    printf("YES");
  else
    printf("NO");
}
