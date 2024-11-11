#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MAX = 1e6 + 10;
bool prime[MAX];
void Si() {
  memset(prime, true, sizeof(prime));
  for (int p = 2; p * p < MAX; p++)
    if (prime[p] == true)
      for (int i = p * p; i < MAX; i += p) prime[i] = false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  Si();
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) cnt++;
    if (cnt == 0) {
      cout << 1 << "\n" << n;
      return 0;
    }
    if (n == 4) {
      cout << 2 << "\n" << 2 << " " << 2;
      return 0;
    }
    if (n == 6) {
      cout << 2 << "\n" << 3 << " " << 3;
      return 0;
    }
    cout << 3 << "\n" << 3 << " ";
    n -= 3;
    for (auto i = 2; i < MAX; i++) {
      if (prime[i] && (n - i > 0 && n - i < MAX && prime[n - i])) {
        cout << i << " " << n - i;
        break;
      }
      int s = n - i;
      bool sol = false;
      if (!prime[i]) continue;
      for (auto j = 2; j < MAX; j++) {
        if (s % j == 0 && prime[j]) break;
        if (prime[j] && j * j > s) {
          cout << i << " " << j;
          sol = true;
          break;
        }
      }
      if (sol) break;
    }
  }
}
