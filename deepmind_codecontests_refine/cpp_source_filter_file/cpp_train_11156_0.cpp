#include <bits/stdc++.h>
using namespace std;
bool isprime(long long int x) {
  if (x == 0 || x == 1) return 0;
  if (x % 2 == 0) return 0;
  for (long long int i = 3; i < x; i++) {
    if (x % i == 0) return 0;
    i++;
  }
  return 1;
}
long long int nextprime(int n) {
  long long int x = n;
  while (true) {
    if (isprime(x)) return x;
    x++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  long long int x = nextprime(n);
  cout << x << endl;
  for (long long int i = 0; i < n; i++)
    cout << i + 1 << " " << (i + 1) % n + 1 << endl;
  for (long long int i = 0; i < x - n; i++)
    cout << i + 1 << " " << (i + 2) % n + 1 << endl;
  return 0;
}
