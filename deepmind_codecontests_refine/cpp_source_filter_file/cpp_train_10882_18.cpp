#include <bits/stdc++.h>
using namespace std;
ofstream fo("test.out");
ifstream fi("test.inp");
long long n, m, k, rs, dem;
long long a[100005], b[100005];
int main() {
  fi >> n >> m;
  int i;
  for (i = 0; i < n; i++) {
    fi >> a[i];
  }
  sort(a, a + n);
  i = 1;
  int j = 0, k = 0;
  while (m > 0) {
    if (i != a[j]) {
      if (m >= i)
        m -= i;
      else
        break;
      b[k] = i;
      i++;
      k++;
      rs++;
    } else {
      i++;
      j++;
    }
  }
  cout << rs << "\n";
  for (i = 0; i < rs; i++) cout << b[i] << " ";
}
