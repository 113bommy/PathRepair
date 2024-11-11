#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  if (m == 1) {
    long long answer = (n / 6) * 6;
    if (n - answer == 4) {
      cout << answer + 1;
    } else if (n - answer == 5) {
      cout << answer + 2;
    } else
      cout << answer;
    return 0;
  }
  if (n == 7 && m == 2) {
    cout << 12;
    return 0;
  }
  if (n > 4) {
    long long answer = (long long)n * m;
    if (answer % 2 == 1) answer -= 1;
    cout << answer;
    return 0;
  }
  if (n <= 2 && m <= 2) {
    cout << 0;
    return 0;
  }
  if (n == 3) {
    if (m == 1) {
      cout << 0;
      return 0;
    }
    if (m == 2) {
      cout << 4;
      return 0;
    }
  }
  if (n == 4 && m == 1) {
    cout << 2;
    return 0;
  }
  long long answer = (long long)n * m;
  if (answer % 2 == 1) answer -= 1;
  cout << answer;
  return 0;
}
