#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int t = n / 2;
  cerr << (s.substr(0, t) == s.substr(t) ? "Yes" : "No") << endl;
}
