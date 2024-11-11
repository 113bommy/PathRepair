#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, a[6], sum = 0, pg;
  cin >> n;
  for (long long i = 0; i <= (long long)5; i++) {
    cin >> a[i];
    sum += a[i];
  }
  n %= sum;
  if (n == 0) {
    n = sum;
  }
  for (long long i = 0; i <= (long long)5; i++) {
    pg += a[i];
    if (n <= pg) {
      cout << i + 1;
      return 0;
    }
  }
  return 0;
}
