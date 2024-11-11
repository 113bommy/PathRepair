#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 100;
int l[maxn], r[maxn];
char t[maxn];
bool mark[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i] >> l[i] >> r[i];
  int ans = 0;
  for (int i = 0; i < 400; i++) {
    int cntA = 0, cntB;
    for (int j = 0; j < n; j++)
      if (l[j] <= i && i <= r[j]) {
        if (t[j] == 'M')
          cntA++;
        else
          cntB++;
      }
    ans = max(ans, min(cntA, cntB));
  }
  cout << 2 * ans << endl;
  return 0;
}
