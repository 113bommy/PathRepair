#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
const int MAXM = 1 << 20;
int a[MAXN];
int res[2][MAXM + 10];
int main() {
  int n;
  cin >> n;
  res[0][0] = 1;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = a[i - 1] ^ a[i];
    sum += res[i % 2][a[i]];
    res[i % 2][a[i]]++;
  }
  cout << sum << endl;
  return 0;
}
