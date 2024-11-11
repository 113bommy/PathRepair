#include <bits/stdc++.h>
using namespace std;
string s1, s2, a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cnt = 0;
int main() {
  int n;
  scanf("%d", &n);
  while (--n) {
    if (n % 2) {
      s1 += a[cnt++];
    } else {
      s1 += a[cnt];
      s1 += a[cnt++];
      n /= 2;
    }
  }
  for (int i = 0; i <= cnt; i++) s2 += a[i];
  cout << s1 + s2 << " " << s2 << endl;
  return 0;
}
