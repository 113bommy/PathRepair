#include <bits/stdc++.h>
using namespace std;
vector<bool> mark(1000000005);
bool is_prime(long long n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  if (n == 2)
    cout << "1" << endl;
  else if (n % 2 == 0)
    cout << "2" << endl;
  else if (is_prime(n))
    cout << "1" << endl;
  else if (is_prime(n - 2))
    cout << "2" << endl;
  else
    cout << "3" << endl;
  return 0;
}
