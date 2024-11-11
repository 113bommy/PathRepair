#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    v[i] = k;
  }
  vector<long long> zeros(n, 0);
  int j = n - 1;
  zeros[j] = 0;
  for (; j >= 0; j--) zeros[j] = (v[j + 1] == 0 ? 1 : 0) + zeros[j + 1];
  long long ret = 0;
  j = 0;
  while (j < n) {
    if (v[j] == 1) {
      ret += zeros[j];
      int k = j + 1;
      while (k < n && v[k] == 0) k++;
      if (k >= n)
        break;
      else
        j = k - 1;
    }
    j++;
  }
  cout << ret;
  return 0;
}
