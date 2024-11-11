#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char s[maxn], t1[maxn], t2[maxn];
int main() {
  int t;
  int n;
  scanf("%d", &t);
  for (int i = 0; i < maxn; i += 2) {
    t1[i] = t2[i + 1] = '1';
    t1[i + 1] = t2[i] = '0';
  }
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s);
    int l0 = 0, l1 = 0;
    int f0 = 0, f1 = 0;
    int tmp = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] == t1[i])
        f0 = 0;
      else {
        if (!f0) l0++;
        f0 = 1;
      }
      if (s[i] == t2[i])
        f1 = 0;
      else {
        if (!f1) l1++;
        f1 = 1;
      }
    }
    cout << min(l0, l1) << "\n";
  }
  return 0;
}
