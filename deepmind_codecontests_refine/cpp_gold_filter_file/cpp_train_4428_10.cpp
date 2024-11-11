#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long int ans = n * (n + 1) / 2;
  ans *= 6;
  ans++;
  cout << ans;
  return 0;
}
