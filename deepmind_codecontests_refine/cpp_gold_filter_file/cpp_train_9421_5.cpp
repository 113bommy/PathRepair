#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m = n * n;
  int a[m], b[m];
  int ch[101] = {0}, cv[101] = {0};
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    ch[a[i]]++;
    cv[b[i]]++;
  }
  ch[a[1]] = 0;
  cv[b[1]] = 0;
  cout << 1 << " ";
  for (int i = 2; i <= m; i++) {
    if (ch[a[i]] != 0 && cv[b[i]] != 0) {
      cout << i << " ";
      ch[a[i]] = 0;
      cv[b[i]] = 0;
    }
  }
  return 0;
}
