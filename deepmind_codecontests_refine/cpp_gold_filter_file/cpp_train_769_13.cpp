#include <bits/stdc++.h>
using namespace std;
int v[500000];
int main() {
  int n, r, i;
  cin >> n;
  r = n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  sort(v + 1, v + n + 1);
  int j = 1;
  i = n / 2 + 1;
  while (j <= n / 2 && i <= n) {
    if (v[j] * 2 <= v[i]) {
      r--;
      j++;
    }
    i++;
  }
  cout << r;
  return 0;
}
