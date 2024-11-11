#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char c;
  int x;
  map<string, int> mp;
  while (n--) {
    cin >> c >> x;
    if (c == '+') {
      string s = "00000000000000000000";
      int in = s.size() - 1;
      while (x) {
        if ((x % 10) % 2) {
          s[in] = '1';
        } else {
          s[in] = '0';
        }
        in--;
        x /= 10;
      }
      mp[s]++;
    } else if (c == '-') {
      string s = "00000000000000000000";
      int in = s.size() - 1;
      while (x) {
        if ((x % 10) % 2) {
          s[in] = '1';
        } else {
          s[in] = '0';
        }
        in--;
        x /= 10;
      }
      mp[s]--;
    } else {
      string s = "00000000000000000000";
      int in = s.size() - 1;
      while (x) {
        if ((x % 10) % 2) {
          s[in] = '1';
        } else {
          s[in] = '0';
        }
        in--;
        x /= 10;
      }
      cout << mp[s] << endl;
    }
  }
  return 0;
}
