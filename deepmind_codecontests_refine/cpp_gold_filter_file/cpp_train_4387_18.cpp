#include <bits/stdc++.h>
using namespace std;
long long flag;
char s, s1, s2, s3, s4, s5, x, x1, x2, x3, x4, x5;
int main() {
  cin >> x >> s;
  cin >> x1 >> s1 >> x2 >> s2 >> x3 >> s3 >> x4 >> s4 >> x5 >> s5;
  flag = 0;
  if (x1 == x || x2 == x || x3 == x || x4 == x || x5 == x) flag++;
  if (s1 == s || s2 == s || s3 == s || s4 == s || s5 == s) flag++;
  if (flag == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
