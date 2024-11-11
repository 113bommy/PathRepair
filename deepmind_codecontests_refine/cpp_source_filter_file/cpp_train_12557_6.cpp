#include <bits/stdc++.h>
using namespace std;
int Calculate(int32_t a) {
  int32_t b = 0;
  b += a;
  while (a / 10 != 0) {
    b += a % 10;
    a = a / 10;
  }
  b += a;
  return b;
}
int main() {
  int32_t n;
  while (cin >> n) {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t counter = 0;
    vector<int32_t> answer;
    if (n < 10) {
      for (int i = 1; i < n; i++) {
        if (2 * i == n) {
          counter++;
          answer.push_back(i);
        }
      }
    } else {
      a = n - (n % 10) - 1;
      b = Calculate(a);
      c = a;
      while (Calculate(c) >= n) {
        c -= 11;
      }
      for (int32_t i = c; i <= n; i++) {
        if (Calculate(i) == n) {
          answer.push_back(i);
          counter++;
        }
      }
    }
    cout << counter << endl;
    for (int32_t i = 0; i < answer.size(); i++) {
      cout << answer[i] << endl;
    }
  }
  return 0;
}
