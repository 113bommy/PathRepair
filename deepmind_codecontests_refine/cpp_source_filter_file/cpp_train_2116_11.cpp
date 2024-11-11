#include <bits/stdc++.h>
using namespace std;
int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
bool prime_check(long long int n) {
  long long int i, j;
  if (n == 1) {
    return false;
  }
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long int fact(long long int n) {
  long long int prod = 1;
  for (long long int i = 1; i <= n; i++) {
    prod = (prod * i) % 1000000007;
  }
  return prod;
}
bool vowl(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int i;
  set<char> se[103];
  for (i = 0; i < n; i++) {
    string second;
    cin >> second;
    for (int j = 0; j < m; j++) se[j].insert(second[j]);
  }
  long long int ans = 1;
  for (i = 0; i < m; i++) {
    ans *= se[i].size() % 1000000007;
  }
  cout << ans % 1000000007 << "\n";
  return 0;
}
