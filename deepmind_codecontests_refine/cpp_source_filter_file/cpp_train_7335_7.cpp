#include <bits/stdc++.h>
using namespace std;
string s1, s2, s;
vector<int> v1, v2;
int main() {
  long long n, m, i, a, b, x = 0, y = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    if (a > 0) {
      x += a;
      v1.push_back(a);
    } else {
      y -= a;
      v2.push_back(a);
    }
  }
  if (x > y)
    puts("first");
  else if (x < y)
    puts("second");
  else {
    int sz1 = v1.size();
    int sz2 = v2.size();
    int sign = 0;
    for (i = 0; i < sz1 && i < sz2; i++) {
      if (v1[i] < v2[i]) {
        sign = 2;
        break;
      } else if (v1[i] > v2[i]) {
        sign = 1;
        break;
      }
    }
    if (sign == 0) {
      if (sz1 > sz2)
        sign = 1;
      else if (sz1 < sz2)
        sign = 2;
    }
    if (sign == 1)
      puts("first");
    else if (sign == 2)
      puts("second");
    else {
      if (a > 0)
        puts("first");
      else
        puts("second");
    }
  }
}
