#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t > 0) {
    string s;
    cin >> s;
    long long int x;
    cin >> x;
    string w(s.size(), '1');
    for (long long int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        if (i - x >= 0) w[i - x] = '0';
        if (i + x <= s.size() - 1) w[i + x] = '0';
      }
    }
    long long int flag = 1;
    for (long long int i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        if ((i - x > 0 && w[i - x] != '1') ||
            (i + x < s.size() - 1 && w[i + x] != '1')) {
          flag = 0;
          break;
        }
      }
    }
    if (flag)
      cout << w << "\n";
    else
      cout << -1 << "\n";
    t--;
  }
  return 0;
}
