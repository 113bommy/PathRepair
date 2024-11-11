#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a, m;
int main() {
  cin >> a >> m;
  bool flag = 0;
  for (int i = 1; i <= m;) {
    if (i * a % m == 0) {
      flag = true;
      break;
    }
    i *= 2;
  }
  if (flag)
    puts("Yes");
  else
    puts("No");
  return 0;
}
