#include <bits/stdc++.h>
using namespace std;
int main() {
  int val;
  string str;
  cin >> val;
  cin >> str;
  string s1 = str.substr(0, val);
  string s2 = str.substr(val, val);
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  if (s1[0] > s2[0]) {
    for (int i = 1; i < val; i++) {
      if (s1[i] <= s2[i]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  } else if (s1[0] < s2[2]) {
    for (int i = 1; i < val; i++) {
      if (s1[i] >= s2[i]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
