#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int count = 0;
  int prev_i, i, prev_j, j;
  prev_i = i = 0;
  prev_j = j = (s.size() / k) - 1;
  int each = s.size() / k;
  if (s.length() < k) {
    cout << "NO";
    return 0;
  }
  while (i <= j) {
    if (s[i] == s[j]) {
      count++;
      i++;
      j--;
    } else {
      cout << "NO";
      return 0;
    }
    if (count == each / 2 || (each == 1 && count == 1)) {
      if (prev_j == s.size() - 1) {
        cout << "YES";
        return 0;
      }
      i = prev_i + each;
      j = prev_j + each;
      count = 0;
      prev_i = i;
      prev_j = j;
    }
  }
}
