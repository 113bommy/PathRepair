#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long int answer = n;
  for (int i = 2; i * i < n; i++) {
    while (n % i == 0) {
      n /= i;
      if (n <= 1) {
        break;
      }
      answer += n;
    }
    if (n <= 1) {
      break;
    }
  }
  cout << answer + 1 << endl;
  return 0;
}
