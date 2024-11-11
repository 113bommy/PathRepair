#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000 + 1000;
int arr[MAXN];
int mrk[MAXN];
int n;
int32_t main() {
  int cur = 0, max_so = 0;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    int num;
    cin >> num;
    if (!mrk[num]) {
      mrk[num] = 1;
      cur++;
    } else {
      mrk[num] = 0;
      cur--;
    }
    max_so = max(max_so, cur);
  }
  cout << max_so << endl;
}
