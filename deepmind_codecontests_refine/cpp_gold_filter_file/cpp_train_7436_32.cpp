#include <bits/stdc++.h>
using namespace std;
void it(string s, int k, int n) {
  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      cout << "PRINT " << s[i - 1] << endl;
      if (i == n) break;
      cout << "RIGHT" << endl;
    }
  } else {
    for (int i = n; i >= 1; i--) {
      cout << "PRINT " << s[i - 1] << endl;
      if (i == 1) break;
      cout << "LEFT" << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 1 || k == n) {
    it(s, k, n);
  } else {
    if (k > n / 2) {
      while (k < n) {
        cout << "RIGHT" << endl;
        k++;
      }
    } else {
      while (k > 1) {
        cout << "LEFT" << endl;
        k--;
      }
    }
    it(s, k, n);
  }
}
