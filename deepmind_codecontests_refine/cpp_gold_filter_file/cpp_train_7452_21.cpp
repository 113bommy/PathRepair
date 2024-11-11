#include <bits/stdc++.h>
using namespace std;
map<int, int> sg, vst;
int k;
int f(int n) {
  if (k == 1) return 1;
  for (int i = 2; i <= (int)sqrt(n); i++)
    if (n % i == 0)
      if (i >= k || n / i >= k) return 1;
  return 0;
}
int main() {
  int n, m;
  sg.clear();
  vst.clear();
  sg[1] = 0;
  vst[1] = 1;
  scanf("%d%d%d", &n, &m, &k);
  if (m > 1 && n % 2 && f(m))
    printf("Timur\n");
  else
    printf("Marsel\n");
  return 0;
}
