#include <bits/stdc++.h>
using namespace std;
vector<int> v(45000, 0);
void sieve() {
  for (int i = 2; i * i < 45000; i++) {
    if (v[i] == 0) {
      v[i] = 1;
      for (int j = 2 * i; j < 45000; j += i) v[j] = v[j] + 1;
    }
  }
}
int main() {
  int n;
  cin >> n;
  sieve();
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (v[i] == 2) ans++;
  }
  std::cout << ans << std::endl;
  return 0;
}
