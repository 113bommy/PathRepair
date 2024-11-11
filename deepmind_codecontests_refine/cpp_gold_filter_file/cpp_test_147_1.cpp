#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long n = s.size();
    long long count = 0;
    for (long long i = 0; i < n; i++) {
      if (s[i] == 'N') {
        count++;
      }
    }
    if (count == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
