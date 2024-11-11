#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  long long int initial;
  cin >> initial;
  char c;
  long long int val = 0;
  for (int i = 0; i < n; i++) {
    cin >> c >> val;
    if (c == '+') {
      val = initial + val;
    }
    if (c == '-') {
      if (initial < val) {
        count++;
        val = initial;
        continue;
      }
      val = initial - val;
    }
    initial = val;
  }
  cout << val << " " << count;
  return 0;
}
