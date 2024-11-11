#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7, N = 1e6 + 10;
int main() {
  long long int time;
  cin >> time;
  while (time--) {
    long long int l = -1, r = -1, n;
    cin >> n;
    string s;
    cin >> s;
    for (long long int i = 1; i < s.size(); i++) {
      if (s[i - 1] == 'a' and s[i] == 'b') {
        l = i, r = i + 1;
        break;
      }
      if (s[i - 1] == 'b' and s[i] == 'a') {
        l = i;
        r = i + 1;
        break;
      }
    }
    cout << l << " " << r << endl;
  }
}
