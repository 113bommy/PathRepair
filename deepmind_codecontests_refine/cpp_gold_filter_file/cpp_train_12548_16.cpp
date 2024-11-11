#include <bits/stdc++.h>
using namespace std;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n;
  cin >> n;
  if (n == 2) {
    cout << -1 << endl;
  } else {
    cout << 6 << endl << 10 << endl << 15 << endl;
    long long counter = 3, sum = 6 * 6;
    for (long long i = 0; i < 21 && counter < n; i++, counter++) {
      cout << sum << endl;
      sum *= 6;
    }
    sum = 10 * 10;
    for (long long i = 0; i < 17 && counter < n; i++, counter++) {
      cout << sum << endl;
      sum *= 10;
    }
    sum = 15 * 15;
    for (long long i = 0; i < 14 && counter < n; i++, counter++) {
      cout << sum << endl;
      sum *= 15;
    }
  }
  return 0;
}
