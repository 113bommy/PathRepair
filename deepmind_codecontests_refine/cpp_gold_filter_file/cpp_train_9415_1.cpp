#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, min;
  cin >> s >> min;
  int t, a = 0;
  for (int i = 0; i < s; i++) {
    cin >> t;
    a += t;
  }
  if ((s - 1) * 10 + a > min) {
    cout << -1 << endl;
    return 0;
  }
  t = (s - 1) * 2;
  while (a + t * 5 < min) t++;
  while (a + t * 5 > min) t--;
  cout << t << endl;
}
