#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 == s2) {
    cout << "YES" << endl;
    exit(0);
  }
  string s[7] = {"monday", "tuesday",  "wednesday", "thursday",
                 "friday", "saturday", "sunday"};
  int index1, index2;
  for (int i = 0; i < 7; i++) {
    if (s[i] == s1) {
      index1 = i;
      break;
    }
  }
  for (int i = 0; i < 7; i++) {
    if (s[i] == s2) {
      index2 = i;
      break;
    }
  }
  int diff = abs(index2 - index1);
  if (index2 < index1) {
    diff -= 2;
  }
  if (diff == 2) {
    cout << "YES" << endl;
  } else if (diff == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
