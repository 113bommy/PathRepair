#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, r = 0, l = 0, c;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> c;
    if (c == 'R')
      r++;
    else
      l++;
  }
  cout << r + l + 1;
}
