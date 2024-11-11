#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    string odd = "";
    string even = "";
    for (int i = 0; i < s.size(); i++) {
      if (s[i] % 2 == 0)
        even += s[i];
      else
        odd += s[i];
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    string d = odd + even;
    string f = even + odd;
    bool q = false;
    for (int i = 0; i < d.size() - 1; i++) {
      if (abs(d[i] - d[i + 1]) == 1) {
        q = true;
        break;
      }
    }
    if (!q) {
      cout << d << endl;
    } else {
      bool w = false;
      for (int i = 0; i < f.size() - 1; i++) {
        if (abs(f[i] - f[i + 1]) == 1) {
          w = true;
          break;
        }
      }
      if (!w)
        cout << f << endl;
      else
        cout << "No answer" << endl;
    }
  }
}
