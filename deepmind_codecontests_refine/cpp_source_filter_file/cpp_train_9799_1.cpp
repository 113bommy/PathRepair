#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  int m, count = 0;
  if (n % 2 == 0)
    m = (n / 2) - 1;
  else
    m = n / 2;
  int k = m - 1;
  int d = m + 1;
  cout << s[m];
  while (count < n) {
    if (count < n) {
      cout << s[d];
      d++;
      count++;
    }
    if (count < n) {
      cout << s[k];
      k--;
      count++;
    }
  }
}
