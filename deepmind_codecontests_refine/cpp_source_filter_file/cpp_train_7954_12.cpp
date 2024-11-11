#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int left = 0, right = 0;
  int pivot = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '^') pivot = i;
  }
  for (int i = 0; i < s.length(); i++) {
    if (i < pivot) {
      if (s[i] != '=') {
        left += (s[i] - '0') * (pivot - i);
      }
    } else {
      if (s[i] != '=') {
        right += (s[i] - '0') * (i - pivot);
      }
    }
  }
  if (left == right)
    cout << "balance";
  else if (left > right)
    cout << "left";
  else
    cout << "right";
}
