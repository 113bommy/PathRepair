#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count;
  char max = 'a';
  for (int i = 0; i < s.length(); i++) {
    if (s[i] > max) {
      max = s[i];
      count = 1;
    } else if (s[i] == max) {
      count++;
    }
  }
  for (int j = 0; j < count; j++) {
    cout << max;
  }
  return 0;
}
