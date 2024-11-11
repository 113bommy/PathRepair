#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, cnt = 0;
  cin >> n;
  string s;
  cin >> s;
  char d[2100];
  int t = n;
  if (n % 2 == 0) {
    m = (n / 2);
    int x = m + 1;
    while (n) {
      d[m] = s[cnt++];
      m--;
      n--;
      d[x] = s[cnt++];
      x++;
      n--;
    }
  } else {
    m = (n / 2) + 1;
    int x = m - 1;
    while (n) {
      d[m] = s[cnt++];
      m++;
      n--;
      if (n < 1) continue;
      d[x] = s[cnt++];
      x--;
      n--;
    }
  }
  for (int i = 1; i <= t; i++) cout << d[i];
  cout << endl;
  return 0;
}
