#include <bits/stdc++.h>
using namespace std;
int count[26];
int xs[100001];
int ys[100001];
int main() {
  long long n;
  cin >> n;
  if (n % 3 != 0) {
    cout << n / 3 + 1;
    return 0;
  }
  for (int i = 9; i <= n * 3; i *= 3) {
    if (n % i != 0) {
      cout << n / i + 1;
      return 0;
    }
  }
  return 0;
}
