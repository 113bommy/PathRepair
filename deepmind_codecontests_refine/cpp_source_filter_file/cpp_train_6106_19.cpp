#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) b[i + 1] = s[i] - '0';
  int l;
  int r;
  l = -1000000005;
  ;
  r = 1000000005;
  for (int i = 5; i <= n; i++) {
    if (b[i] == 1 && b[i - 1] == b[i - 2] && b[i - 2] == b[i - 3] &&
        b[i - 3] == b[i - 4] && b[i - 4] == 0) {
      int m1 = max(a[i - 1], a[i - 2]);
      int m2 = max(a[i - 3], a[i - 4]);
      l = max(l, max(m1, max(m2, a[i])) + 1);
    } else if (b[i] == 0 && b[i - 1] == b[i - 2] && b[i - 2] == b[i - 3] &&
               b[i - 3] == b[i - 4] && b[i - 4] == 1) {
      int m1 = min(a[i - 1], a[i - 2]);
      int m2 = min(a[i - 3], a[i - 4]);
      r = min(r, min(m1, min(m2, a[i])) - 1);
    }
  }
  cout << l << " " << r << endl;
  return 0;
}
