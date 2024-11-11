#include <bits/stdc++.h>
using namespace std;
int n, b[200010], cb, x, maxx = 0;
char s[100005];
int main() {
  cin >> n >> (s + 1);
  for (int i = 1; s[i]; ++i) {
    if (s[i] == '0')
      ++cb;
    else
      --cb;
    if (!(b + 100005)[cb] && cb)
      (b + 100005)[cb] = i;
    else
      maxx = max(maxx, i - (b + 100005)[cb]);
  }
  cout << maxx;
  return 0;
}
