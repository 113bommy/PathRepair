#include <bits/stdc++.h>
using namespace std;
int n, ar[2000], br[2000];
int cnt;
pair<int, int> func(int first) {
  int mx = 0, second, countt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == first || br[i] == 1) continue;
    countt = 1;
    for (int j = 1; j <= n; j++)
      if (j != first && j != i && br[j] == 0) {
        if ((j - first) * (ar[i] - ar[first]) ==
            (ar[j] - ar[first]) * (i - first))
          countt++;
      }
    if (countt >= mx) mx = countt, second = i;
  }
  br[first] = br[second] = 1;
  cnt -= 2;
  cerr << first << ", " << second << '\n';
  for (int i = 1; i <= n; i++)
    if (i != first && i != second && br[i] == 0 &&
        (i - first) * (ar[second] - ar[first]) ==
            (second - first) * (ar[i] - ar[first])) {
      cerr << i << " ";
      cnt--, br[i] = 1;
    }
  cerr << endl;
  return make_pair(first, second);
}
int main() {
  while (cin >> n) {
    memset(br, 0, sizeof(br));
    for (int i = 0; i < n; i++) cerr << br[i] << " ";
    cerr << endl;
    for (int i = 1; i <= n; i++) scanf("%d", ar + i);
    bool ans = 0;
    for (int pa = 1; pa <= 3; pa++) {
      cnt = n;
      memset(br, 0, sizeof(br));
      pair<int, int> p1 = func(pa), p2;
      if (cnt == 0) {
        continue;
      }
      if (cnt == 1) {
        ans = 1;
        break;
      }
      for (int i = 1; i <= n; i++)
        if (br[i] == 0) {
          p2 = func(i);
          break;
        }
      bool ok = 0;
      if ((ar[p1.first] - ar[p1.second]) * (p2.second - p2.first) ==
          (p1.first - p1.second) * (ar[p2.second] - ar[p2.first]))
        ok = 1;
      cerr << ok << " " << cnt << endl;
      if (cnt == 0 && ok) {
        ans = 1;
        break;
      }
    }
    printf((ans) ? "Yes\n" : "No\n");
  }
  return 0;
}
