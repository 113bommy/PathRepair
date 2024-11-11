#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  vector<bool> prime(n + 2, true);
  prime[1] = false;
  prime[0] = false;
  if (n > 2) {
    cout << 2 << "\n";
  } else
    cout << 1 << "\n";
  for (long long int i = 2; i <= n + 1; i++) {
    if (prime[i]) {
      for (long long int j = i * i; j <= n + 1; j += i) {
        prime[j] = false;
      }
      cout << 1 << " ";
    } else
      cout << 2 << " ";
  }
  cout << "\n";
  return 0;
}
