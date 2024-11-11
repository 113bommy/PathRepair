#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    ans += (i * 2 + 1) % (n + 1);
  }
  cout << ans % n;
}
