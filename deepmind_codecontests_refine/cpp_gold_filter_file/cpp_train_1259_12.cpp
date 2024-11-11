#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, j = 0;
    cin >> n;
    string str;
    cin >> str;
    for (int i = 0; i <= (n / 2) - 1; i++) {
      if (str[i] == str[n - 1 - i] || str[i] - 1 == str[n - 1 - i] + 1 ||
          str[i] + 1 == str[n - 1 - i] - 1)
        j++;
    }
    if (j == n / 2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
