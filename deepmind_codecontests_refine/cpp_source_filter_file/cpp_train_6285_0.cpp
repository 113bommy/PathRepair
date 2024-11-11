#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int arr[n];
  int o = 0, c = 0, f = 0;
  arr[0] = 0;
  if (s[0] == '(') {
    arr[0]++;
    o++;
  } else {
    arr[0]--;
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == '(') {
      arr[i] = arr[i - 1] + 1;
      o++;
    } else {
      arr[i] = arr[i - 1] - 1;
      c++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] + f < 0) {
      c--;
      f++;
    }
  }
  cout << max(min(2 * o, 2 * c), 0);
  return 0;
}
