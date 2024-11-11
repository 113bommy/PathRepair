#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, b;
    cin >> s;
    cin >> b;
    int c = 0;
    vector<int> a;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == b[i]) {
        continue;
      }
      if (b[i] != s[0]) {
        c++;
        a.push_back(i + 1);
        reverse(s.begin(), s.begin() + i);
        for (int j = 0; j <= i; j++) {
          if (s[j] == '0') {
            s[j] = '1';
          } else {
            s[j] = '0';
          }
        }
      } else {
        c++;
        a.push_back(1);
        if (s[0] == '1') {
          s[0] = '0';
        } else {
          s[0] = '1';
        }
        c++;
        a.push_back(i + 1);
        reverse(s.begin(), s.begin() + i);
        for (int j = 0; j <= i; j++) {
          if (s[j] == '0') {
            s[j] = '1';
          } else {
            s[j] = '0';
          }
        }
      }
    }
    cout << c << " ";
    for (int i = 0; i < a.size(); i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}
