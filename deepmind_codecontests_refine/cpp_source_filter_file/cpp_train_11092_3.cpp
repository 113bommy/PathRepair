#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, count = 0;
  cin >> n;
  long long int c[n];
  string s;
  cin >> s;
  for (long long int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (long long int i = 1; i < n; i++) {
    if (s.at(i) == 'L' && s.at(i - 1) == 'R') {
      c[count++] = abs(c[i] - c[i - 1]);
    }
  }
  long long int max = c[0];
  for (long long int i = 1; i < count - 1; i++) {
    if (c[i] < max) max = c[i];
  }
  if (count > 0)
    cout << max / 2;
  else
    cout << "-1";
  return 0;
}
