#include <bits/stdc++.h>
using namespace std;
long long t;
long long n;
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> s;
    bool flag = 0;
    for (long long i = 0; i < s.size(); i++) {
      long long numa = 0, numb = 0;
      for (long long j = i; j < s.size(); j++) {
        if (s[j] == 'a') numa++;
        if (s[j] == 'b') numb++;
        if (numa == numb) {
          cout << i << " " << j << endl;
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) cout << "-1 -1" << endl;
  }
  return 0;
}
