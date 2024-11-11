#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, l, o, p;
long long f[110][2];
char s[110];
int a[110];
long long did(int tag) {
  memset(f, 0, sizeof(f));
  f[0][tag] = 1;
  for (i = 0; i < n; i++) {
    if (!a[i + 1])
      f[i + 1][0] = f[i][0];
    else if (a[i])
      f[i + 1][1] = f[i][1] + f[i][0];
    else {
      f[i + 1][0] = f[i - 1][0] + f[i - 1][1];
      f[i + 1][1] = f[i][0] + f[i][1];
    }
  }
  return f[n][tag];
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  o = strcspn(s, "B");
  if (o >= n - 1) return puts("1"), 0;
  for (i = 0; i < n; i++) a[i + 1] = (s[(i + o) % n] == 'A');
  cout << did(0) + did(1) << endl;
  cin >> n;
  return 0;
}
