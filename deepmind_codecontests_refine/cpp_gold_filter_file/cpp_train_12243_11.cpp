#include <bits/stdc++.h>
using namespace std;
bool valid(long long int a, long long int b) {
  char sh1 = (a / 10) + '0';
  char sh2 = (a % 10) + '0';
  char sm1 = (b / 10) + '0';
  char sm2 = (b % 10) + '0';
  if (sh1 == sm2 && sh2 == sm1) {
    return true;
  }
  return false;
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  long long int a = (s[0] - '0') * 10 + (s[1] - '0');
  long long int b = (s[3] - '0') * 10 + (s[4] - '0');
  long long int i;
  if (s[0] == s[4] && s[1] == s[3]) {
    cout << 0;
    return 0;
  }
  for (i = 0; i < 1200; i++) {
    b++;
    if (b == 60) {
      b = 0;
      a = (a + 1) % 24;
    }
    if (valid(a, b)) {
      cout << i + 1;
      break;
    }
  }
}
