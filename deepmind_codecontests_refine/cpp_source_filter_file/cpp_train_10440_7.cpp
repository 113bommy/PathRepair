#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, answer;
  cin >> m >> n;
  if (m == 1)
    answer = n;
  else if (n == 1)
    answer = m;
  else if ((m * n) % 2 == 0) {
    if (m == 2 && n == 2) {
      answer = 4;
    } else if (m == 2 && n != 2) {
      if (n % 4 == 1)
        answer = (m * n + 2) / 2;
      else if (n % 4 == 2)
        answer = (m * n + 4) / 2;
      else if (n % 4 == 3)
        answer = (m * (n - 1) + 4) / 2;
      else
        answer = (m * n) / 2;
    } else if (m != 2 && n == 2) {
      if (m % 4 == 1)
        answer = (m * n + 2) / 2;
      else if (m % 4 == 2)
        answer = (m * n + 4) / 2;
      else if (m % 4 == 3)
        answer = ((m - 1) * n + 4) / 2;
      else
        answer = (m * n) / 2;
    } else
      answer = (m * n) / 2;
  } else if ((m * n) % 2 == 1)
    answer = (m * n - 1) / 2;
  cout << answer;
  return 0;
}
