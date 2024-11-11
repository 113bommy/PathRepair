#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % 1000000007;
    a = (a * a) % 1000000007;
    b >>= 1;
  }
  return ret;
}
void printT(int n, string str) {
  for (int i = int(0); i < int(n); i++) cout << str[i];
  cout << endl;
}
int main() {
  string str;
  cin >> str;
  if (str.length() < 3) {
    cout << "Just a legend" << endl;
    return 0;
  }
  long long c;
  vector<long long> t(str.length());
  t[0] = c = 0;
  for (int i = int(1); i < int(str.length()); i++) {
    while (c && str[c] != str[i]) c = t[c - 1];
    c += str[c] == str[i] ? 1 : 0;
    t[i] = c;
  }
  if (!t.back()) {
    cout << "Just a legend" << endl;
    return 0;
  }
  for (int i = int(0); i < int(str.length() - 1); i++) {
    if (t[i] == t.back()) {
      printT(t.back(), str);
      return 0;
    }
  }
  if (t[t.back()] - 1 > 0) {
    printT(t[t.back()] - 1, str);
    return 0;
  }
  cout << "Just a legend" << endl;
  return 0;
}
