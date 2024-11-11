#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int sx[100005], sy[100005], sz[100005];
int main() {
  cin >> s;
  cin >> n;
  for (long long i = (0); i < (s.size()); i++) {
    sx[i + 1] = sx[i];
    sy[i + 1] = sy[i];
    sz[i + 1] = sz[i];
    if (s[i] == 'x')
      sx[i + 1]++;
    else if (s[i] == 'y')
      sy[i + 1]++;
    else if (s[i] == 'z')
      sz[i + 1]++;
  }
  int a[3];
  for (int REP_i = 0; REP_i < (n); REP_i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    a[0] = sx[r] - sx[l - 1];
    a[1] = sy[r] - sy[l - 1];
    a[2] = sz[r] - sz[l - 1];
    sort(a, a + 3);
    if (r - l + 1 <= 2) {
      puts("NO");
      continue;
    }
    if ((a[0] == a[1] && a[1] == a[2]) || (a[0] == a[1] - 1 && a[1] == a[2]) ||
        (a[2] == a[1] + 1 && a[0] == a[1]))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
