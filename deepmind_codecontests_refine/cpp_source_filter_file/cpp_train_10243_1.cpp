#include <bits/stdc++.h>
using namespace std;
string a, b, c, d, s;
int main() {
  cin >> a >> b;
  int m1 = 0, m2 = 0;
  for (int i = 0; i < (int)a.size(); i++) m1 += (a[i] == '1');
  for (int i = 0; i < (int)a.size(); i++) m2 += (b[i] == '1');
  if (m1 % 2) m1++;
  if (m1 >= m2)
    puts("YES");
  else
    puts("NO");
  return 0;
}
