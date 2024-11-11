#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int j = 1; j <= n; j++) cin >> a[j];
  long long m = 0;
  for (int i = 1; i <= n - 1; i++) {
    int t = log2(n - i);
    m += a[i];
    cout << m << endl;
    a[i + (int)pow(2, t)] += a[i];
  }
  return 0;
}
