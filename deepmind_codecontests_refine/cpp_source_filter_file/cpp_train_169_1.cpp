#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int max = 0;
  int index;
  for (int i = 0; i < n - 2; i++) {
    int count = 0;
    for (int j = i + 1; j < n - 1; j++) {
      if (s[j] == s[i] && s[j + 1] == s[i + 1]) {
        count++;
      }
    }
    if (count > max) {
      max = count;
      index = i;
    }
  }
  cout << s[index] << s[index + 1];
  return 0;
}
