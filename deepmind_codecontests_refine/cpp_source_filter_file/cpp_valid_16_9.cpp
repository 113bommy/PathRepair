#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string b = s;
    sort(s.begin(), s.end());
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (b[i] != s[i]) {
        count++;
      }
    }
    cout << count;
    t--;
  }
  return 0;
}
