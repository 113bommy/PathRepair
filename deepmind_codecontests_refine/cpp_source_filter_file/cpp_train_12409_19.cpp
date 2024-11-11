#include <bits/stdc++.h>
using namespace std;
bool check(string s) {
  int b[10] = {0};
  for (int i = 0; i < s.length(); i++) b[s[i] - '0']++;
  for (int i = 0; i < 10; i++) {
    if (b[i] > 1) {
      return 0;
    }
  }
  return 1;
}
int main() {
  long int a, b;
  cin >> a >> b;
  for (int i = a + 1; i <= b; i++) {
    string s;
    s = to_string(i);
    if (check(s) == 1) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
