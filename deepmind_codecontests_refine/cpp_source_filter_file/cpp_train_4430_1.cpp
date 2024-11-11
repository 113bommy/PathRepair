#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  unsigned long long c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
  vector<int> vv;
  string s;
  for (int i = 0; i < 16; i++) {
    cout << pri[i] << endl;
    cin >> s;
    if (s == "yes") vv.push_back(pri[i]);
  }
  if (!vv.size()) {
    cout << "prime\n";
    return 0;
  }
  if (vv.size() > 1) {
    cout << "composite\n";
    return 0;
  }
  if (vv.size() == 1) {
    if (vv[0] * vv[0] > 100) {
      cout << "composite\n";
      return 0;
    }
    cout << vv[0] * vv[0] << endl;
    cin >> s;
    if (s == "yes")
      cout << "composite\n";
    else
      cout << "prime\n";
  }
  return 0;
}
