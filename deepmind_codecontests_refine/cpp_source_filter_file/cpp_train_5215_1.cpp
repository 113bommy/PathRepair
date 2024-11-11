#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], sum[maxn];
int main() {
  string str;
  cin >> str;
  int cnt = 0;
  int pre = 0;
  for (int i = 0; i < str.size();) {
    int r = (str[i] - '0') % 3;
    if (r == 0)
      cnt++, i++, pre = 0;
    else {
      if (r + pre == 3)
        cnt++, i++, pre = 0;
      else {
        if (!pre)
          pre = r, i++;
        else {
          if (i + 2 < str.size()) {
            cnt++;
            pre = 0;
          }
          i += 2;
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
