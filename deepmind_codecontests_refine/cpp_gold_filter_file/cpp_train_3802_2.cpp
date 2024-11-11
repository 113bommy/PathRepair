#include <bits/stdc++.h>
const int N = (int)3e5 + 1;
using namespace std;
map<int, int> m;
int a[N];
int main() {
  int n, x, k = 1, h = 0;
  int pos = 0;
  scanf("%d", &x);
  for (int i{1}; i <= x; ++i) {
    scanf("%d", &n);
    m[n]++;
    if (m[n] == 2) {
      h++;
      pos += 2;
      a[pos - 1] = k;
      a[pos] = i;
      k = i + 1;
      m.clear();
    }
  }
  a[pos] = x;
  if (h == 0)
    puts("-1");
  else {
    printf("%d\n", h);
    for (int i{1}; i <= pos; i++) {
      printf("%d ", a[i]);
    }
  }
  return 0;
}
