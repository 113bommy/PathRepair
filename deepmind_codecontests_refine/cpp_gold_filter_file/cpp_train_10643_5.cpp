#include <bits/stdc++.h>
using namespace std;
int get(int xt) {
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    ans *= 2;
    ans += xt % 2;
    xt /= 2;
  }
  return ans;
}
int main() {
  char a[110] = "";
  gets(a);
  int len = strlen(a);
  int xt = 0;
  for (int i = 0; i < len; i++) {
    int tmp = a[i];
    tmp = get(tmp);
    if (i != len)
      cout << (xt - tmp + 256) % 256 << endl;
    else
      cout << (xt - tmp + 256) % 256;
    xt = tmp;
  }
  return 0;
}
