#include <bits/stdc++.h>
using namespace std;
int main() {
  size_t a, b, n;
  cin >> a >> b >> n;
  size_t *v = new size_t[n - 1];
  v[0] = a;
  v[1] = b;
  for (int i = 2; i < n - 1; i++) {
    v[i] = v[i - 1] + v[i - 2];
  }
  cout << v[n - 2] << endl;
  delete[] v;
  return 0;
}
