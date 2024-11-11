#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x[101], d[101];
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &d[i]);
  bool flag = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      if (x[i] + d[i] == x[j] && x[j] + d[j] == x[i]) {
        flag = 1;
        goto here;
      }
    }
here:;
  if (flag)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
