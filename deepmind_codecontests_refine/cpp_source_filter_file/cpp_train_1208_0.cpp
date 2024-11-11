#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  scanf("%d", &n);
  int cnt = 0;
  int kk = 0;
  while (n) {
    while (cnt <= n) {
      n -= cnt;
      s += ('a' + kk);
      cnt++;
    }
    cnt = 0;
    kk++;
  }
  cout << s << endl;
  return 0;
}
