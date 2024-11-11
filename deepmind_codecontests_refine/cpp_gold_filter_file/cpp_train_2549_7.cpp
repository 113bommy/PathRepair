#include <bits/stdc++.h>
using namespace std;
int k, n;
string s;
int main() {
  cin >> s;
  n = s.length();
  k = 26 * (n + 1);
  k -= n;
  cout << k;
}
