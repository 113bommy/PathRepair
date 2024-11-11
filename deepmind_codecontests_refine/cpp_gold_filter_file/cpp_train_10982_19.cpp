#include <bits/stdc++.h>
using namespace std;
bool prime[1200];
void sieve() {
  memset(prime, 0, sizeof(prime));
  prime[0] = prime[1] = 1;
  for (int i = 4; i < 1200; i += 2) prime[i] = 1;
  for (int i = 3; i <= sqrt(1200); i += 2) {
    if (!prime[i]) {
      for (int j = i * i; j < 1200; j += i + i) prime[j] = 1;
    }
  }
}
int main() {
  int n, k, i;
  cin >> n;
  sieve();
  vector<int> ans;
  for (i = 2; i <= n; i++) {
    if (prime[i]) continue;
    k = 1;
    while (k <= n / i) {
      k = k * i;
      ans.push_back(k);
    }
  }
  cout << ans.size() << endl;
  for (i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
