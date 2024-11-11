#include <bits/stdc++.h>
using namespace std;
bool compare(const int a, const int b) { return a % 2 == 1; }
int main() {
  int n, a, b;
  int total = 0;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  char last = 'x';
  int sum = a + b;
  for (int i = 0; i < n; i++) {
    if (s[i] == '.') {
      int choose = 0;
      if (last == 'A') choose = 1;
      if (last != 'A' && last != 'B') {
        choose = a > b ? 0 : 1;
      }
      if (choose == 0 && a > 0) {
        a--;
        s[i] = 'A';
      }
      if (choose == 1 && b > 0) {
        b--;
        s[i] = 'B';
      }
    }
    last = s[i - 1];
  }
  cout << sum - a - b;
  return 0;
}
