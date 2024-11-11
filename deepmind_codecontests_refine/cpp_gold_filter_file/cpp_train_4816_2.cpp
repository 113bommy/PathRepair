#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  string s;
  long sum = 0;
  long r, l;
  long summ = 0;
  long p = 0;
  cin >> t;
  for (long i = 0; i < t; i++) {
    cin >> n;
    cin >> s;
    for (long j = 0; j < n; j++) {
      if (sum == 0 && s[j] == ')')
        l++;
      else if (s[j] == '(') {
        sum++;
        p++;
      } else if (s[j] == ')') {
        r++;
        p--;
        if (p < 0) {
          summ++;
          p = 0;
        }
      }
    }
    if (l != 0)
      cout << l + summ << endl;
    else if (l == 0)
      cout << summ << endl;
    sum = 0;
    r = 0;
    l = 0;
    summ = 0;
    p = 0;
  }
}
