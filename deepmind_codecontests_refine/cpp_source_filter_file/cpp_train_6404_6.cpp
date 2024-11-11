#include <bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
  if (x == 0 || x == 1) return false;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) return false;
  return true;
}
int main() {
  string s, m;
  cin >> s >> m;
  string sol;
  for (int i = 0; i < s.size(); ++i) {
    int a = s[i] - '0';
    int b = m[i] - '0';
    sol.push_back((a & b) + '0');
  }
  cout << sol << endl;
  return 0;
}
