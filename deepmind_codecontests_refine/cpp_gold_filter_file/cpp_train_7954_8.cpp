#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int pos;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s.at(i) == '^') {
      pos = i;
      break;
    }
  }
  long long leftsum = 0, rightsum = 0, k = 1, j = 1;
  for (int i = pos - 1; i >= 0; i--) {
    if (isdigit(s.at(i))) leftsum += k * (s.at(i) - '0');
    k++;
  }
  for (int i = pos + 1; i < s.length(); i++) {
    if (isdigit(s.at(i))) rightsum += j * (s.at(i) - '0');
    j++;
  }
  if (rightsum == leftsum)
    cout << "balance";
  else if (rightsum < leftsum)
    cout << "left";
  else
    cout << "right";
  return 0;
}
