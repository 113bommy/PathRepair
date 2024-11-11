#include <bits/stdc++.h>
using namespace std;
signed long long n, m, answer;
signed long long calc(signed long long n, signed long long m) {
  signed long long answer;
  if (m - n >= 1) {
    answer = n;
  } else {
    answer =
        m + (signed long long)ceil((sqrt(1.0 + 8.0 * (n - m)) - 1.0) / 2.0);
  }
  return answer;
}
int main() {
  cin >> n >> m;
  cout << calc(n, m);
  return 0;
}
