#include <bits/stdc++.h>
using namespace std;
map<int, int> name;
const int mm = 1e6;
long long int d[mm];
long long int dd[mm];
int main() {
  int n, i, j, s, l;
  cin >> n;
  for (i = 0; i < n; i++) cin >> d[i];
  if (n == 1) {
    printf("1");
    printf("L");
    return 0;
  }
  i = 0;
  j = n - 1;
  s = 0;
  if (d[i] < d[j]) {
    l = d[i];
    i++;
    dd[s++] = 0;
  } else {
    l = d[j];
    j--;
    dd[s++] = 1;
  }
  while (1) {
    if (d[i] < l && d[j] < l) break;
    if (d[i] < l && d[j] > l) {
      dd[s++] = 1;
      l = d[j];
      j--;
      if (l == n) break;
      continue;
    }
    if (d[i] > l && d[j] < l) {
      dd[s++] = 0;
      l = d[i];
      i++;
      if (l == n) break;
      continue;
    }
    if (d[i] < d[j]) {
      dd[s++] = 0;
      l = d[i];
      i++;
    } else {
      dd[s++] = 1;
      l = d[j];
      j--;
    }
    if (l == n) break;
  }
  printf("%d\n", s);
  for (i = 0; i < s; i++) {
    if (dd[i] == 0)
      printf("L");
    else
      printf("R");
  }
}
