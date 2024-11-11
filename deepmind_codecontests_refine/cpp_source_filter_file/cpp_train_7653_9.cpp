#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 321;
int a[maxN];
int mark[maxN];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int f = 0; f < k + 1; f++) {
    memset(mark, 0, sizeof mark);
    int t = 1;
    for (int i = 0; i < n; i++)
      if (a[i] != k) t = 0;
    if (t) {
      cout << f << endl;
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (!mark[a[i]] && a[i] != k) {
        mark[a[i]] = 1;
        a[i]++;
      }
    }
  }
  return 0;
}
