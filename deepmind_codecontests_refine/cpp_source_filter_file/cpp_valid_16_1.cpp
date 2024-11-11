#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int length;
    cin >> length;
    string s, s1;
    cin >> s;
    s1 = s;
    int count = 0;
    sort(s1.begin(), s1.end());
    for (int i = 0; i < length; i++) {
      if (s[i] != s1[i]) {
        count++;
      }
    }
    cout << count;
  }
  return 0;
}
