#include <bits/stdc++.h>
using namespace std;
vector<int> v1;
int main() {
  int n, k, z, m;
  cin >> n;
  m = n;
  k = z = 2;
  v1.push_back(2);
  while (m != 0) {
    z += k;
    if (z % n == 0)
      v1.push_back(n);
    else
      v1.push_back(z % n);
    --m;
    ++k;
  }
  for (int i = 0; i < (n - 1); ++i) cout << v1[i] << " ";
  return 0;
}
