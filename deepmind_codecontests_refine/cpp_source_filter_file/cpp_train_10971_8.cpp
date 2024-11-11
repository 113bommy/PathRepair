#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int b, d, lena, lenc, cnt, now;
  char a[105], c[105];
  int cishu[105];
  int tail[105];
  cin >> b >> d;
  cin >> a >> c;
  lena = strlen(a);
  lenc = strlen(c);
  for (int i = 0; i < lenc; i++) {
    now = i;
    for (int j = 0; j < lena; j++) {
      if (c[now % lenc] == a[j]) now++;
    }
    cishu[i] = now % lenc;
    tail[i] = now / lenc + 1;
  }
  cnt = 0;
  now = 0;
  for (int i = 0; i < b; i++) {
    cnt += cishu[now];
    now = tail[now];
  }
  cout << cnt / d << endl;
  return 0;
}
