#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    string s;
    cin >> s;
    int l[3005], r[3005];
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    int cnt = 0, t1 = 0, t2 = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'L') {
        l[t1++] = i;
        continue;
      }
      if (s[i] == 'R') {
        r[t2++] = i;
        continue;
      }
    }
    if (l[0] == r[0]) {
      cout << n << endl;
      continue;
    }
    if (l[0] == -1) {
      cout << r[0] << endl;
      continue;
    }
    if (r[0] == -1) {
      cout << n - l[0] - 1 << endl;
      continue;
    }
    if (l[0] < r[0]) {
      cnt += l[0] + 1;
      for (int i = 1; i < t1; ++i) {
        int t = l[i] - r[i - 1];
        cnt += t + 1;
        if (t % 2 == 0) cnt--;
      }
      if (t1 == t2) cnt += n - r[t2 - 1];
    } else {
      for (int i = 1; i < t1; ++i) {
        int t = l[i] - r[i];
        cnt += t + 1;
        if (t % 2 == 0) cnt--;
      }
      if (t2 > t1) cnt += n - r[t2 - 1];
    }
    cout << n - cnt << endl;
  }
  return 0;
}
