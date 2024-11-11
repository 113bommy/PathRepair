#include <bits/stdc++.h>
using namespace std;
bool check(string s, int k) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[i % k]) {
      return false;
    }
  }
  return true;
}
int divisors(string a, string b) {
  int l1 = a.size();
  int l2 = b.size();
  int count = 0;
  for (int i = 1; i <= min(l1, l2); i++) {
    if ((l1 % i == 0) && (l2 % i == 0)) {
      if (a.substr(0, i) == b.substr(0, i)) {
        if (check(a, i) && check(b, i)) {
          count++;
        }
      }
    }
  }
  return count;
}
int main() {
  string a, b;
  cin >> a;
  cin >> b;
  int c = divisors(a, b);
  cout << c;
}
