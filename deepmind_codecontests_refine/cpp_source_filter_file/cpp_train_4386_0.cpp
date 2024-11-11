#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long n, temp = 0;
  cin >> n >> s;
  for (long long i = 0; i < n - 1; i++) {
    if (s[i] > s[i + 1]) {
      temp = i;
      break;
    }
  }
  if (temp == 0) {
    for (long long i = 0; i < n - 1; i++) {
      cout << s[i];
    }
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    if (temp != i) {
      cout << s[i];
    }
  }
  return 0;
}
