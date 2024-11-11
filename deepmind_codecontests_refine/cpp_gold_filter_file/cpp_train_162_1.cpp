#include <bits/stdc++.h>
using namespace std;
clock_t T;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long n, m;
  cin >> n >> m;
  if (n == m && n % 2)
    cout << n;
  else
    cout << 2;
}
