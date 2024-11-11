#include <bits/stdc++.h>
using namespace std;
int k, n;
string s;
int main() {
  cin >> s;
  n = s.length();
  k = 26 * n;
  k -= n;
  cout << k;
}
