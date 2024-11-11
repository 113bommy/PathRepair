#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int ans = n * (n + 1) / 2;
  ans *= 6;
  ans++;
  cout << ans;
  return 0;
}
