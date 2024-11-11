#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j, i, s = 0, av, ip, cp = 100000000;
  int a[10000];
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= 100; i++) {
    int c = 0;
    for (j = 0; j < n; j++) {
      if (a[j] < i - 1) c += abs(a[j] - i + 1);
      if (a[j] > i + 1) c += abs(a[j] - i - 1);
    }
    if (c < cp) cp = c, ip = i;
  }
  cout << ip << " " << cp << endl;
  return 0;
}
