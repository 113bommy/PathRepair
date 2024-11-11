#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "";
  int n, k, i, j, br = 0;
  cin >> n >> k;
  for (i = 1; i <= k - 1; i++) {
    for (j = 2; j * j <= n; j++) {
      if (n % j == 0) {
        s = s + to_string(j) + " ";
        n = n / j;
        br++;
        break;
      }
    }
  }
  if (br == k - 1) {
    s = s + to_string(n);
  } else {
    s = to_string(-1);
  }
  cout << s << endl;
  return 0;
}
