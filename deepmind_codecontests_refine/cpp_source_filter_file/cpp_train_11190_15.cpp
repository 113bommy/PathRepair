#include <bits/stdc++.h>
using namespace std;
long long w, m, sz, i, a[40];
int main() {
  cin >> w >> m;
  while (m) a[sz++] = m % w, m /= w;
  for (i = 0; i <= sz; i++) {
    if (a[i] != 0 && a[i] != 1 && a[i] != w - 1 && a[i] != w) {
      cout << "NO";
      break;
    } else {
      if (a[i] == w - 1 || a[i] == w) {
        a[i + 1]++;
      }
    }
  }
  cout << "YES";
  return 0;
}
