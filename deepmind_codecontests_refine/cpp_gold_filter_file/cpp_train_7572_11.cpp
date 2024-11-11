#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int a[20005];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = (1); i < (n + 1); i++) {
    if (n % i == 0) {
      reverse(s.begin(), s.begin() + i);
    }
  }
  cout << s << endl;
  return 0;
}
