#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long current = 0;
  long long answer = 0;
  while (n >= current * 10 + 9) {
    current = current * 10 + 9;
    answer += 9;
  }
  n = n - current;
  while (n) {
    answer += n % 10;
    n /= 10;
  }
  cout << answer << endl;
  return 0;
}
