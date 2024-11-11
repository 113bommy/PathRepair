#include <bits/stdc++.h>
using namespace std;
long long int num[1000010];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m, a, b, l, r, d;
  cin >> n >> m;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  l = m - 1;
  r = n - m + 1;
  if (l >= r) {
    d = m - 1;
  } else
    d = m + 1;
  cout << d << endl;
  return 0;
}
