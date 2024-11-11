#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, t1 = 9, t2 = 1, t3 = 10, answer = 0;
  cin >> n;
  while (t3 < n) {
    answer += t1 * t2;
    t1 *= 10;
    t2++;
    t3 *= 10;
  }
  answer += (n - t3 / 10 + 1) * t2;
  cout << answer << endl;
  return 0;
}
