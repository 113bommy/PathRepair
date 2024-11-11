#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  s.reserve(101);
  char arr[] = {'n', 'i', 'e', 't'};
  cin >> s;
  int no[4] = {0}, t = s.length();
  vector<int> v;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < t; j++) {
      if (arr[i] == s[j]) no[i]++;
    }
  }
  int n = no[0];
  no[0] /= 3;
  no[2] /= 3;
  for (int i = 1; i < 4; i++) v.push_back(no[i]);
  sort(no, no + 4);
  sort(v.begin(), v.end());
  if (v[0] > 1) {
    for (int i = v[0]; i > 0; i--) {
      if (n >= 2 * i + 1) {
        cout << i;
        break;
      }
    }
  } else
    cout << no[0];
  return 0;
}
