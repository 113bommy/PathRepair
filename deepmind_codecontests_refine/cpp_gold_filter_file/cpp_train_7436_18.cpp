#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k > n / 2) {
    for (int i = 1; i <= n - k; i++) {
      cout << "RIGHT\n";
    }
    long long int j = s.size() - 1;
    for (int i = n * 2 - 1; i > 0; i--) {
      if (i % 2 != 0)
        cout << "PRINT " << s[j] << "\n", j--;
      else
        cout << "LEFT\n";
    }
    return 0;
  } else {
    for (int i = 1; i < k; i++) {
      cout << "LEFT\n";
    }
    long long int j = 0;
    for (int i = 0; i < n * 2 - 1; i++) {
      if (i % 2 == 0)
        cout << "PRINT " << s[j] << "\n", j++;
      else
        cout << "RIGHT\n";
    }
    return 0;
  }
}
