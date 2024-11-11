#include <bits/stdc++.h>
using namespace std;
long long n, a[20] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, d;
string s[20] = {"monday", "tuesday",  "wednesday", "thursday",
                "friday", "saturday", "sunday"};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s1, s2;
  cin >> s1 >> s2;
  long long a1 = 0, a2 = 0;
  for (int i = 0; i < 6; i++)
    if (s1 == s[i]) {
      a1 = i;
      break;
    }
  for (int i = 0; i < 6; i++)
    if (s2 == s[i]) {
      a2 = i;
      break;
    }
  n = a1;
  for (int i = 0; i < 12; i++) {
    n = a1;
    n += a[i];
    n %= 7;
    if (n == a2) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
