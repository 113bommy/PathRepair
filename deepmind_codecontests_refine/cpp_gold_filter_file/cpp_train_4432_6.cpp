#include <bits/stdc++.h>
using namespace std;
int main(void) {
  string str;
  cin >> str;
  int len = str.size();
  unsigned long long n = 0, ans;
  for (register int i = 0; i < len - 1; i++) n = n * 10 + (str[i] - '0');
  ans = (n - 1) / 4;
  ans *= 16;
  if (n % 4 == 2 || n % 4 == 0) ans += 7;
  switch (str[len - 1]) {
    case 'f': {
      ans++;
      break;
    }
    case 'e': {
      ans += 2;
      break;
    }
    case 'd': {
      ans += 3;
      break;
    }
    case 'a': {
      ans += 4;
      break;
    }
    case 'b': {
      ans += 5;
      break;
    }
    case 'c': {
      ans += 6;
      break;
    }
  }
  cout << ans;
  return 0;
}
