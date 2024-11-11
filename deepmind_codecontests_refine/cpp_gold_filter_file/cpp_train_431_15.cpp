#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 7;
int match[N];
int cnt = 0;
bool is[N];
int main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int k = 0; k < t; ++k) {
    int n, m;
    cin >> n >> m;
    cnt = 0;
    memset(is, 0, sizeof(is));
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      if (!is[a - 1] && !is[b - 1]) {
        is[a - 1] = is[b - 1] = true;
        if (cnt < n) match[cnt] = i + 1, cnt++;
      }
    }
    if (cnt == n) {
      cout << "Matching\n";
      for (int i = 0; i < n; ++i) cout << match[i] << " ";
      cout << "\n";
    } else {
      cout << "IndSet\n";
      for (int i = 0, cntK = 0; i < 3 * n && cntK < n; ++i) {
        if (!is[i]) {
          cout << i + 1 << " ";
          cntK++;
        }
      }
      cout << "\n";
    }
  }
  cout << endl;
  return 0;
}
