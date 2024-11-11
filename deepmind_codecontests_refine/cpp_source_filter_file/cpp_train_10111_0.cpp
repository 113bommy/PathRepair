#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int MX = 1e5 + 5;
int n;
int a[MX], b[MX];
vector<int> vec[MX];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    vec[n - a[i]].push_back(i);
  }
  int j = 0, p = 0;
  for (int i = 1; i <= n; i++) {
    for (auto x : vec[i]) {
      if (!j) {
        j = i;
        p++;
      }
      b[x] = p;
      j--;
    }
    if (j) {
      puts("Impossible");
      return 0;
    }
  }
  puts("possible");
  for (int i = 1; i <= n; i++) printf("%d%c", b[i], " \n"[i == n]);
  return 0;
}
