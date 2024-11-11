#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const int MOD = 1e9 + 7;
bool prime[1234567];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(prime, true, sizeof prime);
  prime[1] = false;
  for (int i = 2; i <= 100; i++) {
    if (prime[i])
      for (int j = i * i; j <= 1000; j += i) prime[j] = false;
  }
  int N;
  cin >> N;
  for (int i = 1; i <= 1000; i++) {
    if (prime[N * i + 1] == false) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
