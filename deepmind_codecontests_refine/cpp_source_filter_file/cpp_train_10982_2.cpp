#include <bits/stdc++.h>
using namespace std;
bool mark[1001];
int ans, n;
bool isPrime(int n) {
  int c = 1;
  if (n == 2) return 1;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) c = 0;
  return c;
}
int main() {
  vector<int> p;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (isPrime(i)) {
      int j = i;
      while (j <= n) {
        ans++;
        p.push_back(j);
        j *= j;
      }
    }
  }
  cout << ans << endl;
  for (int i = 0; i < ans; i++) cout << p[i] << " ";
}
