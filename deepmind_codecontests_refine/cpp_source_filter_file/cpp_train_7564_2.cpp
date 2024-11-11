#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char s[n + 2];
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = n; i >= 1; i--) {
    if (n % i == 0) {
      for (int j = 1; j <= i / 2; j++) {
        swap(s[j], s[i - j + 1]);
      }
    }
  }
  for (int i = 1; i <= n; i++) cout << s[i];
}
