#include <bits/stdc++.h>
using namespace std;
int x[1000006];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ;
  int a[500005], n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int c = 0, d = -1, cnt = 0;
  int i, j, p = -1;
  while (c < n) {
    x[a[c]]++;
    if (x[a[c]] == 1) cnt++;
    if (cnt <= k) {
      if (c - d > p) {
        p = c - d;
        i = c + 1;
        j = d + 2;
      }
    }
    if (cnt > k) {
      while (cnt > k) {
        d++;
        x[a[d]]--;
        if (x[a[d]] == 0) cnt--;
      }
    }
    c++;
  }
  cout << j << " " << i << endl;
}
