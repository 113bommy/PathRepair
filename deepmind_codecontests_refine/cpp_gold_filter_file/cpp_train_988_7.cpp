#include <bits/stdc++.h>
using namespace std;
long long n, m;
int s, p, i, j, k, z;
string s1, s2;
int const md = 1000000;
stack<char> st;
int a[5];
int main() {
  int k1 = 0, k2 = 0, k3 = 0;
  cin >> k1 >> k2;
  for (i = 1; i <= k1; i++) {
    cin >> k3;
    n = n * k2 + k3;
  }
  cin >> k1 >> k2;
  for (i = 1; i <= k1; i++) {
    cin >> k3;
    m = m * k2 + k3;
  }
  if (n > m)
    cout << '>';
  else if (n < m)
    cout << '<';
  else
    cout << '=';
}
