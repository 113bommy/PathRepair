#include <bits/stdc++.h>
using namespace std;
long long int binpow(long long int x, long long int m) {
  if (m == 0) return 1;
  long long int ans = binpow(x, m / 2);
  ans = ans * ans;
  if (m % 2) ans *= x;
  return ans;
}
void comeon() {
  long long int n, m;
  cin >> n >> m;
  long long int x = log2(1e8 + 1);
  if (n >= x) {
    cout << m;
    return;
  }
  long long int cal = binpow(2, n);
  cout << m % cal;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int testcases = 1;
  while (testcases--) {
    comeon();
  }
}
