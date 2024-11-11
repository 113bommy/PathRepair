#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long ans;
  for (int i = 2; i < n; i++) {
    long long x = i * (i + 1);
    ans += x;
  }
  cout << ans;
  return 0;
}
