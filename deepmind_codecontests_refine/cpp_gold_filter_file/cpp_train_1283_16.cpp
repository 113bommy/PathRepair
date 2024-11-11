#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int a[N], b[N], f[N], s[N];
int btot, anstot;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", s + i);
    if (s[i] > 0)
      a[s[i]]++;
    else
      b[-s[i]]++, btot++;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] + btot - b[i] == m) {
      f[i] = 1;
      anstot++;
    }
  }
  anstot = anstot == 1 ? 1 : 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] > 0) {
      puts(!f[s[i]] ? "Lie" : anstot ? "Truth" : "Not defined");
    } else {
      puts(!f[-s[i]] ? "Truth" : anstot ? "Lie" : "Not defined");
    }
  }
  return 0;
}
