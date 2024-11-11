#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n;
int v[N];
int main(void) {
  scanf("%d", &n);
  int ones = 0;
  for (int(i) = (0); (i) < (n); ++(i)) {
    scanf("%d", &v[i]);
    if (v[i] == 1) ones++;
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i; j < n; j++) {
      if (v[j] == 0)
        cnt++;
      else
        cnt--;
      mx = max(mx, cnt);
    }
  }
  printf("%d\n", ones + mx);
  return 0;
}
