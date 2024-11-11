#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, i, f = 0, f1 = 0, d, v = 10, c = 0;
  cin >> n;
  vector<int> digits;
  while (n > 0) {
    d = (n % v);
    n = n / v;
    digits.push_back(d);
    c++;
  }
  reverse(digits.begin(), digits.end());
  for (i = 0; i < c;) {
    if (digits[i] == 1 && digits[i + 1] == 4 && digits[i + 2] == 4)
      i = i + 3, f = 1;
    else if (digits[i] == 1 && digits[i + 2] == 4)
      i = i + 2, f = 1;
    else if (digits[i] == 1)
      i++, f = 1;
    else
      i++, f1 = 1;
  }
  cout << (f == 1 && f1 == 0 ? "YES" : "NO") << endl;
}
