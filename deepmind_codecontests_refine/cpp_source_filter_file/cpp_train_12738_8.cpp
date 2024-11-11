#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int nextPrime(int n) {
  if (n == 2) return 3;
  int x = n + 1;
  while (true) {
    if (isPrime(x)) return x;
    x++;
  }
}
int main() {
  int n;
  cin >> n;
  vector<int> p;
  if (n % 2 != 0)
    cout << -1;
  else {
    for (int i = 0; i < n; i++) {
      p.push_back(i + 1);
    }
    for (int i = 0; i < n - 1;) {
      int temp = p[i + 1];
      p[i + 1] = p[i];
      p[i] = temp;
      cout << p[i] << " " << p[i + 1];
      i += 2;
    }
  }
  return 0;
}
