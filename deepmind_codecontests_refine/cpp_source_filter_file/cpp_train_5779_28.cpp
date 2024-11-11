#include <bits/stdc++.h>
using namespace std;
bool is_prime(int a) {
  int sq = sqrt(a);
  for (int i = 3; i <= sq; i += 2) {
    if (a % i == 0) return 0;
  }
  return 1;
}
int main() {
  int n, i, j;
  cin >> n;
  if (is_prime(n))
    cout << "1" << endl << n;
  else if (is_prime(n - 2))
    cout << "2" << endl
         << "2"
         << " " << n - 2;
  else if (is_prime(n - 4))
    cout << "2" << endl
         << "2"
         << " "
         << "2"
         << " " << n - 4;
  else {
    for (i = n - 6;; i -= 2) {
      if (is_prime(i)) break;
    }
    int sum = n - i;
    for (j = 3;; j += 2) {
      if (is_prime(j) && is_prime(sum - j)) break;
    }
    cout << "3" << endl;
    cout << i << " " << j << " " << sum - j;
  }
  return 0;
}
