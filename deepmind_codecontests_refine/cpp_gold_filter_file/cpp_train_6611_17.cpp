#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
int n, m;
int b[N], f[N];
int cnt[N], res[N], pos[N];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = int(1); i <= int(n); ++i) {
    cin >> f[i];
    ++cnt[f[i]];
    pos[f[i]] = i;
  }
  bool amb = 0;
  for (int i = int(1); i <= int(m); ++i) {
    cin >> b[i];
    if (cnt[b[i]] == 0) {
      cout << "Impossible\n";
      return 0;
    }
    if (cnt[b[i]] > 1)
      amb = 1;
    else
      res[i] = pos[b[i]];
  }
  if (amb) {
    cout << "Ambiguity\n";
  } else {
    cout << "Possible\n";
    for (int i = int(1); i <= int(m); ++i) cout << res[i] << " ";
    cout << "\n";
  }
  return 0;
}
