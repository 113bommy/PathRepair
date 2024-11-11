#include <bits/stdc++.h>
using namespace std;
map<long long int, int> m;
bool isPrime(long long int a) {
  for (long long int i = 2; i * i <= a; i++)
    if (a % i == 0) return false;
  return true;
}
int f(long long int a, long long int &move) {
  auto it = m.find(a);
  if (it == m.end()) {
    if (isPrime(a)) return m[a] = 0;
    for (long long int i = 2; i * i <= a; i++) {
      if (a % i == 0) {
        if (f(i, move) == 1) {
          move = i;
          return m[a] = 0;
        }
        if (f(a / i, move) == 1) {
          move = a / i;
          return m[a] = 0;
        }
      }
    }
    return m[a] = 1;
  }
  return it->second;
}
int main() {
  long long int n, r = 0;
  cin >> n;
  if (f(n, r) == 0) {
    cout << 1 << endl << r;
  } else {
    cout << 2;
  }
}
