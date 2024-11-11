#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    long long x = s.size();
    if (x > 11) {
      cout << s[0] << x - 2 << s[x - 1] << endl;
    } else {
      cout << s << endl;
    }
  }
}
