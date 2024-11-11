#include <bits/stdc++.h>
using namespace std;
long long expo(int p, int y) {
  if (p == 1)
    return 2 % y;
  else if (p == 0)
    return 1;
  else {
    long long q = expo(p / 2, y);
    q = (q * q) % y;
    if (p % 2 == 0) {
      return q;
    } else {
      return ((2 % y) * q) % y;
    }
  }
}
int main() {
  long long int n, m, k;
  long long int score;
  cin >> n >> m >> k;
  long long int maxPoss = ((n / k) * (k - 1)) + (n % k);
  if (m <= maxPoss) {
    cout << m << endl;
    return 0;
  }
  m -= maxPoss;
  score = ((2 * k) % 1000000009) * expo(m, 1000000009);
  score %= 1000000009;
  score += ((n / k - m) * (k - 1)) % 1000000009;
  score %= 1000000009;
  score += (n % k);
  score %= 1000000009;
  cout << score << endl;
  return 0;
}
