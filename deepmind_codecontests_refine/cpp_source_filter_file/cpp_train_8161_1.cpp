#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, m, n;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (i == j)
        cout << k << " ";
      else
        cout << 0 << "";
    cout << endl;
  }
}
