#include <bits/stdc++.h>
using namespace std;
int n[20], k[5], m;
int main() {
  n[1] = 1;
  n[2] = 1;
  n[3] = 0;
  n[4] = 1;
  n[5] = 0;
  n[6] = 0;
  n[7] = 0;
  n[8] = 1;
  n[9] = 1;
  n[10] = 1;
  n[11] = 0;
  n[12] = 1;
  n[13] = 1;
  n[14] = 0;
  n[15] = 1;
  n[16] = 0;
  scanf("%d", &m);
  printf("%d", n[m]);
  return 0;
}
