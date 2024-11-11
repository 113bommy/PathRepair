#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, answer;
  cin >> a;
  for (int i = 5; i > 0;) {
    if (a == 0) break;
    if (a >= 5) {
      a = a - 5;
      ++answer;
    } else if (a >= 4) {
      a = a - 4;
      ++answer;
    } else if (a >= 3) {
      a = a - 3;
      ++answer;
    } else if (a >= 2) {
      a = a - 2;
      ++answer;
    } else if (a >= 1) {
      a = a - 1;
      ++answer;
    }
  }
  cout << answer << endl;
  return 0;
}
