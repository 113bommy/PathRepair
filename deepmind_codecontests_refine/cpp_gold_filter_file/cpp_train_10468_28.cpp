#include <bits/stdc++.h>
using namespace std;
inline int fibon(int n) {
  return ((1 / sqrt(5)) *
          (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)));
};
int len(char s[100005]) {
  int i = 0;
  while (s[i] != '\0') i++;
  return i;
}
int ab(int x) { return x > 0 ? x : -x; }
int p(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  int ans = 8;
  char s[3];
  cin >> s;
  if ((s[0] == 'a' && s[1] == '1') || (s[0] == 'a' && s[1] == '8') ||
      (s[0] == 'h' && s[1] == '1') || (s[0] == 'h' && s[1] == '8')) {
    cout << 3;
    return 0;
  }
  if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8') {
    cout << 5;
    return 0;
  }
  cout << 8;
  return 0;
}
