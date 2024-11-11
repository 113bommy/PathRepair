#include <bits/stdc++.h>
const int64_t base = 1e9 + 7;
using namespace std;
int64_t n, a[500010], b[500010], bd[50010], res;
bool dx[50001];
vector<int> v;
int main() {
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i <= s.size() - 1; i++) {
    if (s[i] == '1')
      bd[i + 1] = 1;
    else
      bd[i + 1] = 0;
  }
  for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i <= 100000; i++) {
    int64_t ss = 0;
    for (int j = 1; j <= n; j++) {
      if (i < b[j]) {
        if (bd[j] == 1) ss++;
      } else {
        int pp = (i - b[j]) / a[j];
        if (pp % 2 == 0 && bd[j] == 0) ss++;
        if (pp % 2 != 0 && bd[j] == 1) ss++;
      }
    }
    res = max(res, ss);
  }
  cout << res;
}
