#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  long long n = ((int)((a).size())), cur = 0, cnt = 1;
  for (int i = 0; i < (int)(n - 1); ++i) {
    if ((a[i] - '0') + (a[i + 1] - '0') == 9)
      cur++;
    else if ((a[i] - '0') + (a[i + 1] - '0') != 9 && cur > 0) {
      if (cur % 2 == 0) cnt *= cur / 2 + 1;
      cur = 0;
    }
  }
  if (cur) {
    if (cur % 2 == 0) cnt *= cur / 2 + 1;
    cur = 0;
  }
  cout << cnt;
}
