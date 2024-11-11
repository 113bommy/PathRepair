#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char aa[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    sort(aa + 1, aa + 1 + n);
    int tp = 1, tt = aa[1];
    for (int i = 2; i <= n; i++) {
      if (aa[i] > tt) {
        tt = aa[i];
        tp++;
      }
    }
    cout << tp << endl;
  }
  return 0;
}
