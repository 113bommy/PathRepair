#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, m, b[MAX], f[MAX], pos[MAX], cnt[MAX];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    pos[f[i]] = i;
    cnt[f[i]]++;
  }
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= m; i++)
    if (cnt[b[i]] == 0) {
      cout << "Impossible";
      return 0;
    }
  for (int i = 1; i <= m; i++)
    if (cnt[b[i]] > 1) {
      cout << "Ambiguity";
      return 0;
    }
  cout << "Possible\n";
  for (int i = 1; i <= m; i++)
    if (pos[b[i]] != 0) cout << pos[b[i]] << " ";
}
