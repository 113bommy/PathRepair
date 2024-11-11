#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, l, m = 0;
  cin >> k;
  int a[k + 1];
  for (i = 1; i <= k; i++) {
    cin >> l;
    a[l] = i;
  }
  for (i = 2; i <= k; i++) {
    m += abs(a[i] - a[i - 1]);
  }
  cout << m << endl;
}
