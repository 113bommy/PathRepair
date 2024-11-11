#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, count_u = 0, count_d = 0, count_l = 0, count_r = 0, x1, x2;
  string s;
  cin >> n;
  cin >> s;
  int size = s.size();
  for (i = 0; i < size; i++) {
    if (s[i] == 'U')
      count_u++;
    else if (s[i] == 'D')
      count_d++;
    else if (s[i] == 'L')
      count_l++;
    else
      count_r++;
  }
  if (count_u == count_d == count_l == count_r) {
    x1 = count_u + count_d;
    x2 = count_l + count_r;
  } else {
    if (count_u <= count_d) {
      x1 = count_u * count_u;
    }
    if (count_d <= count_u) {
      x1 = count_d * count_d;
    }
    if (count_l <= count_r) {
      x2 = count_l * count_l;
    }
    if (count_r <= count_l) {
      x2 = count_r * count_r;
    }
  }
  cout << x1 + x2;
  return 0;
}
