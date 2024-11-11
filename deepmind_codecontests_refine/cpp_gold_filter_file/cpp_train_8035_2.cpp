#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
set<int> t;
int T, n;
int a[maxn], num[maxn];
int lpos[maxn], rpos[maxn];
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) lpos[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) rpos[a[i]] = i;
    for (int i = n; i >= 1; i--) lpos[a[i]] = i;
    int lastpos = 0, len = 0, num = 0, maxlen = 0;
    for (int i = 1; i <= n; i++) {
      if (lpos[i]) {
        if (lastpos < lpos[i])
          len++;
        else
          len = 1;
        num++;
        maxlen = max(len, maxlen);
        lastpos = rpos[i];
      }
    }
    cout << num - maxlen << endl;
  }
}
