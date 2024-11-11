#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  string s;
  cin >> s;
  for (i = n; i >= 2; i--)
    if (n % i == 0) reverse(s.begin(), s.begin() + i);
  cout << s;
}
