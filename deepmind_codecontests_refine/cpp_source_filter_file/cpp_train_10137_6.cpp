#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, i, a, b;
  string s;
  cin >> n >> s;
  if (n % 2 == 0) {
    for (i = 0; i < n - 2; i += 2) {
      cout << s[i] << s[i + 1] << "-";
    }
    cout << s[n - 2] << s[n - 1] << endl;
  } else {
    for (i = 0; i < n - 2; i += 2) {
      cout << s[i] << s[i + 1] << "-";
    }
    cout << s[n - 3] << s[n - 2] << s[n - 1] << endl;
  }
}
