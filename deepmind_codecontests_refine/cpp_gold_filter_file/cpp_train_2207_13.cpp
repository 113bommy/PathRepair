#include <bits/stdc++.h>
using namespace std;
int Q, n, t1[30], t2[30];
string T, S;
int doit(int x) {
  int now = 0, res = 0, ans = 0;
  for (int k = 0; k < x; k++) {
    res = 0;
    now = 0;
    for (int i = k; i < x; i++) {
      int fl = 0;
      for (int j = now; j < x; j++) {
        if (T[j] == S[i]) {
          now = j + 1;
          res++;
          fl = 1;
          break;
        }
      }
      if (!fl) break;
      ans = max(ans, res);
    }
  }
  return ans;
}
int main(void) {
  cin >> Q;
  while (Q--) {
    cin >> n >> T >> S;
    int fl = 0;
    memset(t1, 0, sizeof(t1));
    memset(t2, 0, sizeof(t2));
    for (int i = 0; i < n; i++) t1[T[i] - 'a']++;
    for (int i = 0; i < n; i++) t2[S[i] - 'a']++;
    for (int i = 0; i < 28; i++)
      if (t1[i] != t2[i]) {
        cout << "-1" << endl;
        fl = 1;
        break;
      }
    if (!fl) cout << n - doit(n) << endl;
  }
}
