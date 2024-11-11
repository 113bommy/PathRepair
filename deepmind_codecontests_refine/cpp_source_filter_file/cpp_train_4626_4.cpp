#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, p, q, k = 0, c[101] = {0};
  cin >> n >> a >> b;
  for (int i = 1; i < n; i++) {
    cin >> p >> q;
    for (int j = p; j < q; j++) c[j] = 1;
  }
  for (int i = a; i <= b; i++)
    if (c[i] == 0) k++;
  cout << k;
  return 0;
}
