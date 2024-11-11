#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (s[n - 1] == '#') {
    cout << "NO" << endl;
    return 0;
  }
  long long x = 0;
  for (long long i = 0; i < s.size(); i++) {
    if (s[i] == '#')
      x++;
    else {
      if (x >= k) {
        cout << "NO" << endl;
        return 0;
      }
      x = 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
