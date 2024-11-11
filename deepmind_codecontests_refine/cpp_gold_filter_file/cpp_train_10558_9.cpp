#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string weights;
  cin >> weights;
  int left = 0, right = 0, ind = 0;
  while (ind < s.size() && s[ind] != '|') left++, ind++;
  right = s.size() - left - 1;
  string a, b;
  a = s.substr(0, left);
  b = s.substr(ind + 1, s.size());
  if (abs(left - right) > weights.size() ||
      (left % 2 == right % 2 && weights.size() % 2 == 1) ||
      (left % 2 != right % 2 && weights.size() % 2 == 0)) {
    cout << "Impossible";
  } else {
    int index = 0;
    if (left < right)
      while (left < right) a += weights[index++], left++;
    else
      while (right < left) b += weights[index++], right++;
    for (int i = index; i < weights.size(); i++) {
      if (i & 1)
        a += weights[i];
      else
        b += weights[i];
    }
    cout << a << "|" << b;
  }
  return 0;
}
