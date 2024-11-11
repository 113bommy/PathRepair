#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int k = 1;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    v[i] = i;
  }
  int j = 1;
  int d = n;
  n--;
  while (n != 0) {
    int p = (j + k) % d;
    if (p == 0) p = d;
    k++;
    j = p;
    cout << v[p] << ' ';
    n--;
  }
  cin >> j;
  return 0;
}
