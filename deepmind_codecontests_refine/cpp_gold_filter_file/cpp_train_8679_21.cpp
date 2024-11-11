#include <bits/stdc++.h>
using namespace std;
int n, x;
bool cek[3005];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    cek[x] = 1;
  }
  for (int i = 1; i <= 3001; i++) {
    if (!cek[i]) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
