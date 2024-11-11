#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  cout << max(1, int(n * (long double)sqrt((long double)(2))) * 4) << '\n';
  return 0;
}
