#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  string s;
  cin >> n >> s;
  for (int i = 1; i < n - 1; i++) {
    if (s.at(i) < s.at(i - 1)) {
      cout << "YES" << endl;
      cout << i << " " << i + 1;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
