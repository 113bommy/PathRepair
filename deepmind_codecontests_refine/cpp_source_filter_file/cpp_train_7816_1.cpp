#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, count = 0;
  string s;
  cin >> n >> s;
  sort(s.begin(), s.end());
  for (i = 0; i < n; i++) {
    if (s[i] == s[i + 1]) {
      count++;
    }
  }
  if (n = 1)
    cout << "Yes" << endl;
  else if (count > 0) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}
