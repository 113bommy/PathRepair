#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = 0;
    vector<int> a;
    int count = 1;
    char sp = s[0];
    for (int i = 1; i < n; i++) {
      if (s[i] == sp) {
        count++;
      } else {
        a.push_back(count);
        sp = s[i];
        count = 1;
      }
      if (i == n - 1) {
        if (s[i] == s[0]) {
          if (a.size() > 0) {
            a[0] += count;
          } else {
            a.push_back(count);
          }
        } else {
          a.push_back(count);
        }
      }
    }
    for (int i = 0; i < a.size(); i++) {
      result += a[i] / 3;
    }
    if (a.size() == 1 && a[0] >= 4) {
      result++;
    }
    cout << result << endl;
  }
}
