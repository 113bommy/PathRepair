#include <bits/stdc++.h>
using namespace std;
bool cmp2(int a, int b) { return a > b; }
int main() {
  string str, t;
  cin >> str >> t;
  int mun[10] = {0};
  for (int i = 0; i < t.length(); i++) {
    mun[t[i] - '0']++;
  }
  sort(t.begin(), t.end());
  int m = t.length() - 1;
  for (int i = 0; i < str.length(); i++) {
    if (m > 0) {
      if (str[i] < t[m]) {
        cout << t[m];
        m--;
      } else {
        cout << str[i];
      }
    } else {
      cout << str[i];
    }
  }
  return 0;
}
