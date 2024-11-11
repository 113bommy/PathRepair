#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int mul(int x, int y) {
  x = (1LL * x * y) % mod;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  char s1[100] = {'\0'};
  char s2[100] = {'\0'};
  cin >> s1 >> s2;
  char a[100] = {'\0'};
  a[0] = s1[0];
  int k = 1;
  for (int i = 1; s1[i] != '\0'; i++) {
    char c = s1[i];
    if (s2[i - 1] != '\0' && c < s2[0]) {
      a[k] = s1[i];
      k++;
    } else {
      break;
    }
  }
  a[k] = s2[0];
  for (int i = 0; a[i] != '\0'; i++) {
    cout << a[i];
  }
}
