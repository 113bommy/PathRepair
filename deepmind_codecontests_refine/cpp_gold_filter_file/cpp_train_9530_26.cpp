#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long n, a, b, x = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> s >> a >> b;
    if (a >= 2400 & b > a) x++;
  }
  if (x > 0)
    cout << "YES";
  else
    cout << "NO";
}
