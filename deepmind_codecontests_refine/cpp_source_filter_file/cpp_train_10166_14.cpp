#include <bits/stdc++.h>
using namespace std;
int maxn = 100001;
bool ok(long long int a, long long int b) {
  for (long long int i = 2; i <= sqrt(b) + 1; i++) {
    if (a % i == 0 && i <= b) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  int flag = 0;
  while (1) {
    if (k <= n) break;
    if (ok(k, n)) {
      cout << k;
      return 0;
    }
    k--;
  }
  cout << "-1";
  return 0;
}
