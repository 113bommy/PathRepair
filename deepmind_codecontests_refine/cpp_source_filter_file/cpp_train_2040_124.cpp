#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return (a + b);
}
template <typename T>
bool prime(T n) {
  if (n <= 1) {
    return false;
  }
  T i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    ++i;
  }
  return true;
}
void solveTask() {
  int n;
  cin >> n;
  cout << (n - 2) / 2 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solveTask();
  return 0;
}
