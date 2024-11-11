#include <bits/stdc++.h>
using namespace std;
int d[1000000];
int main() {
  int sl = 0;
  for (int i = '0'; i <= '9'; i++) {
    d[i] = sl;
    sl++;
  }
  for (int i = 'A'; i <= 'Z'; i++) {
    d[i] = sl;
    sl++;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    d[i] = sl;
    sl++;
  }
  d['-'] = sl++;
  d['_'] = sl;
  string s;
  cin >> s;
  long long ans = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    int n = d[int(s[i])];
    int d = 0;
    while (n) {
      d++;
      if (n % 2 == 0) {
        ans = ans * 3 % (int(1e9) + 7);
      }
      n = n / 2;
    }
    for (int j = d; j < 6; j++) {
      ans = ans * 3 % (int(1e9) + 7);
    }
  }
  cout << ans;
}
