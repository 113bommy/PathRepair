#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, sm = 1;
  string s;
  cin >> n;
  cin >> s;
  long long int ar[n + 1];
  s = '*' + s;
  for (i = 1; i <= n; i++) cin >> ar[i];
  for (i = 1; i <= n; i++) {
    if (s[sm] == '>')
      sm += ar[sm];
    else
      sm -= ar[sm];
    if (sm < 1 || sm > n) {
      cout << "FINITE" << endl;
      return 0;
    }
  }
  cout << "INFINITE" << endl;
  return 0;
}
