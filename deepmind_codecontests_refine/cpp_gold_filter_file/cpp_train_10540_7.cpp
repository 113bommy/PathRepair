#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  long long n = s.size();
  long long a = 0, b = 0;
  for (auto f : s) {
    a += (f == '1');
    b += (f == '0');
  }
  long long z = n - a - b;
  if (a < b + z) {
    cout << "00" << endl;
  }
  if (n % 2 == 0 && s[n - 1] != '0') {
    long long a1 = a, b1 = b;
    if (s[n - 1] == '?') {
      a1++;
    }
    if (a1 <= n / 2 && b1 <= n / 2) {
      cout << "01" << endl;
    }
  } else if (s[n - 1] != '0') {
    long long a1 = a, b1 = b;
    if (s[n - 1] == '?') {
      a1++;
    }
    if (a1 <= n / 2 + 1 && b1 <= n / 2) {
      cout << "01" << endl;
    }
  }
  if (n % 2 == 0 && s[n - 1] != '1') {
    long long a1 = a, b1 = b;
    if (s[n - 1] == '?') {
      b1++;
    }
    if (a1 <= n / 2 && b1 <= n / 2) {
      cout << "10" << endl;
    }
  } else if (s[n - 1] != '1') {
    long long a1 = a, b1 = b;
    if (s[n - 1] == '?') {
      b1++;
    }
    if (a1 <= n / 2 + 1 && b1 <= n / 2) {
      cout << "10" << endl;
    }
  }
  if (a + z > b + 1) {
    cout << "11" << endl;
  }
}
