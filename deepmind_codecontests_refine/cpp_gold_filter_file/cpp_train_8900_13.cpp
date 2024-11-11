#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, hi, k, c, p;
  int T[100000];
  int T2[100000];
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> hi;
    T[i] = hi;
    T2[i] = T[i];
  }
  std::sort(T2, T2 + n);
  k = 0;
  c = 0;
  p = 0;
  while (k < n) {
    p += T[k] - T2[k];
    if (p == 0) c++;
    k++;
  }
  cout << c << endl;
  return 0;
}
