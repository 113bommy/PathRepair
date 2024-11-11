#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string s1, s2;
  for (int i = 0; i < n; i++) {
    s1.push_back(s[i]);
  }
  for (int i = 2 * n - 1; i >= n; i--) {
    s2.push_back(s[i]);
  }
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  bool flag1 = true, flag2 = true;
  for (int i = 0; i < n; i++) {
    if (s1[i] <= s2[i]) {
      flag1 = false;
    }
  }
  for (int i = 0; i < n; i++) {
    if (s1[i] >= s2[i]) {
      flag2 = false;
    }
  }
  if (flag1 == true or flag2 == true) {
    cout << "YES" << endl;
  } else {
    cout << "No" << endl;
  }
}
