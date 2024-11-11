#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  do {
    char s[10] = "OO|OOOOO\n";
    int i = n % 10;
    if (i > 4) {
      s[0] = '-';
      i -= 5;
    } else {
      s[1] = '-';
    }
    s[i + 3] = '-';
    cout << s;
    n /= 10;
  } while (n);
  return 0;
}
