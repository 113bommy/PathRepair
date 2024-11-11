#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 0, may = 0, cont = 1;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  i = 1;
  while (i <= n) {
    if (a[i] > may) may = a[i];
    if (i >= may) {
      cont++;
      i++;
    } else
      i++;
  }
  cout << cont << '\n';
  return 0;
}
