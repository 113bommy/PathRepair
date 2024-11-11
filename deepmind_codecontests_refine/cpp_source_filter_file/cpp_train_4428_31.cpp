#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long ans = 1;
  ans += (n * (n + 1) / 2);
  cout << ans * 6 << endl;
  return 0;
}
