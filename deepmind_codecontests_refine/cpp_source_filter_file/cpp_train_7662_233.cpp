#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int ans;
  if (n == 2) {
    ans = 3;
  } else {
    ans = n + 2;
  }
  cout << ans;
  return 0;
}
