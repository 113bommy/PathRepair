#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, x, l, r;
  scanf("%d%d", &n, &m);
  int pos = 0, neg = 0;
  for (int i = int(0); i < int(n); i++) {
    scanf("%d", &x);
    if (x == -1)
      neg++;
    else
      pos++;
  }
  for (int i = int(0); i < int(m); i++) {
    scanf("%d%d", &l, &r);
    int val = r - l + 1;
    int mini = min(neg, pos);
    if ((val % 2) == 0) {
      if ((val / 2) <= mini)
        cout << "1" << endl;
      else
        cout << "0" << endl;
    } else
      cout << "0" << endl;
  }
  return 0;
}
