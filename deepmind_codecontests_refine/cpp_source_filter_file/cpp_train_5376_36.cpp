#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  long long n, m;
  cin >> n >> m;
  if (n > 60) {
    cout << m;
  } else {
    long long x = 1 << n;
    cout << m % x;
  }
  return 0;
}
