#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int n, a[maxn], b[maxn];
vector<int> ans;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    ans.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%1d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%1d", &b[i]);
    int delta = 0, len = n, L = 1, R = n;
    bool dir = 0;
    while (len) {
      if (dir) {
        int op = a[L] ^ delta;
        if (op != b[len]) {
          if (a[L] == a[R]) {
            dir ^= 1, delta ^= 1;
          } else {
            a[R] ^= 1;
            ans.push_back(1);
            dir ^= 1, delta ^= 1;
          }
          ans.push_back(len);
          --R;
        } else {
          ++L;
        }
      } else {
        int op = a[R] ^ delta;
        if (op != b[len]) {
          if (a[R] == a[L]) {
            dir ^= 1, delta ^= 1;
          } else {
            a[L] ^= 1;
            ans.push_back(1);
            dir ^= 1, delta ^= 1;
          }
          ans.push_back(len);
          ++L;
        } else {
          --R;
        }
      }
      --len;
    }
    printf("%d ", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
