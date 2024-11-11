#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long answer = 0;
  if (a <= c && a <= d) {
    answer += 256 * a;
  } else if (c <= a && c <= d) {
    answer += 256 * c;
    a -= c;
    if (a <= b) {
      answer += 32 * a;
    } else {
      answer += 32 * b;
    }
  } else if (d <= a && d <= c) {
    answer += 256 * d;
    a -= d;
    if (a <= b) {
      answer += 32 * a;
    } else {
      answer += 32 * b;
    }
  }
  cout << answer << endl;
  return 0;
}
