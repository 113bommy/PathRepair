#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long int INFF = 1e17;
const double EPS = 1e-9;
const long long int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, i, j, ans = 0;
  cin >> n;
  if (n <= 2) {
    cout << 0 << endl;
    return 0;
  }
  i = n;
  j = 2;
  while (i != j) {
    ans++;
    i--;
    j++;
  }
  printf("%d\n", ans);
  ;
  return 0;
}
