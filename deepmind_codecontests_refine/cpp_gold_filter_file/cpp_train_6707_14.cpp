#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 1000;
  int y;
  int arr[4] = {0, 0, 0, 0};
  string s;
  cin >> s;
  for (int j = 0; j < s.length(); j++) {
    if (s[j] == 't')
      arr[0]++;
    else if (s[j] == 'i')
      arr[1]++;
    else if (s[j] == 'e')
      arr[2]++;
    else if (s[j] == 'n')
      arr[3]++;
  }
  arr[3] = (arr[3] - 1) / 2;
  arr[2] /= 3;
  for (int i = 0; i < 4; i++) {
    if (arr[i] < x) {
      y = x;
      x = arr[i];
    }
  }
  cout << x;
  return 0;
}
