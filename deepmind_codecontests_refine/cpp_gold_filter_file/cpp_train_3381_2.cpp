#include <bits/stdc++.h>
using namespace std;
unsigned long long power[600005];
unsigned long long hasher(string s) {
  unsigned long long h = 0;
  unsigned long long B = 29;
  unsigned long long M = 32345678913937;
  for (int i = 0; i < s.size(); i++) {
    h = h * B + s[i];
    power[i] = B;
    B = B * 10;
  }
  cout << h << endl;
  return h;
}
int main() {
  long a, b, s;
  cin >> a >> b >> s;
  long m = fabs(a) + fabs(b);
  if (s < m)
    cout << "No";
  else if ((m - s) % 2)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}
