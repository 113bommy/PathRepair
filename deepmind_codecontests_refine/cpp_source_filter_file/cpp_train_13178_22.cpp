#include <bits/stdc++.h>
using namespace std;
int a[5000005];
char s[5000005];
int main() {
  scanf("%s", s);
  int l = 0, r = 0, v = 1, kq = 0;
  for (int i = 0; s[i]; i++) {
    l = l * 17 + s[i];
    r = r + s[i] * v;
    v *= 17;
    if (l == r) a[i + 1] = a[(i + 1) / 2] + 1;
    kq += a[i + 1];
  }
  cout << kq;
}
