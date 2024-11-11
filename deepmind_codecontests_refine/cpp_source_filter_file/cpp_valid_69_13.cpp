#include <bits/stdc++.h>
using namespace std;
string inttostr(long long n) {
  string s = "";
  while (n) {
    s = (char)(n % 10 + '0') + s;
    n /= 10;
  }
  return s;
}
long long findafter(string a, long long n, long long x) {
  for (long long i = x + 1; i < a.size(); i++) {
    if (a[i] == n) {
      return i;
    }
  }
  return -1;
}
long long atob(string a, string b) {
  long long curr = -1;
  long long ans = 0;
  for (long long i = 0; i < b.size(); i++) {
    if (findafter(a, b[i], curr) == -1) {
      ans += a.size() - curr - 1;
      ans += b.size() - i;
      return ans;
    } else {
      ans += findafter(a, b[i], curr) - curr - 1;
      curr = findafter(a, b[i], curr);
    }
  }
  if (curr < a.size() - 1) {
    ans += a.size() - curr - 1;
  }
  return ans;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string s = inttostr(n);
    long long x = 1, mn = 1000000000000;
    for (long long i = 0; i < 40; i++) {
      mn = min(mn, atob(s, inttostr(x)));
      x *= 2;
    }
    cout << mn << "\n";
  }
}
