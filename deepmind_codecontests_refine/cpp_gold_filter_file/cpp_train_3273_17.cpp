#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a[100001] = {0}, n, i, j, k;
  cin >> n;
  long long int b[n];
  for (i = 0; i < n; i++) {
    cin >> j >> b[i];
    a[j]++;
  }
  for (i = 0; i < n; i++) {
    cout << n - 1 + a[b[i]] << " " << n - 1 - a[b[i]] << endl;
  }
  return 0;
}
