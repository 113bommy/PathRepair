#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long a = 0, b = 0, c = 0;
  long long l = 0;
  vector<long long> v;
  v.push_back(0);
  for (long long i = 1; i < s.size(); i++) {
    if (s[i] == 'v' && s[i - 1] == 'v') {
      l++;
    }
    v.push_back(l);
  }
  for (long long i = 1; i < s.size(); i++) {
    if (s[i] == 'o') {
      long long x = v[i - 1];
      long long y = l - v[i];
      b += y * x;
    }
  }
  cout << b << endl;
}
