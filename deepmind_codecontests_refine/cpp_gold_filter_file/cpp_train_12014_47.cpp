#include <bits/stdc++.h>
using namespace std;
void solve() {}
bool isPrime(int a) {
  for (int i = 2; i * i <= a; ++i) {
    if (a % i == 0) return false;
  }
  return true;
}
int x = 2;
int prime() {
  while (true) {
    if (isPrime(x)) {
      x++;
      return x - 1;
    } else
      x++;
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    cout << prime() << " ";
  }
  cout << '\n';
  return 0;
}
