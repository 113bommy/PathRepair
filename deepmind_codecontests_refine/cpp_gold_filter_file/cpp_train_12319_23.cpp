#include <bits/stdc++.h>
using namespace std;
int mas[5000000], f[5000000], n, e;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
    f[mas[i]] = mas[i];
  }
  for (int i = 1; i < (1ull << (22)); i++) {
    for (int j = 0; j < 22; j++) {
      if ((i & (1ull << (j))) && (f[i - (1ull << (j))]))
        f[i] = f[i - (1ull << (j))];
    }
  }
  for (int i = 0; i < n; i++) {
    if (f[((1ull << (22)) - 1) ^ mas[i]])
      cout << f[((1ull << (22)) - 1) ^ mas[i]] << " ";
    else
      cout << "-1 ";
  }
  return 0;
}
