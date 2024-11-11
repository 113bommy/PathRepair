#include <bits/stdc++.h>
using namespace std;
long long a[2010], b[2010];
long long pre[2010];
bool can[2010];
map<long long, int> MAP;
set<long long> ans;
set<long long> exist;
int main() {
  int ANS = 0;
  int k, n;
  cin >> k >> n;
  for (int i = 1; i <= k; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) pre[i] = pre[i - 1] + a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) MAP[b[i]] = i, exist.insert(b[i]);
  for (int i = 1; i <= k; i++) {
    memset(can, 0, sizeof(can));
    int now = b[1];
    can[MAP[b[1]]] = 1;
    for (int j = i + 1; j <= k; j++) {
      now += a[j];
      if (exist.find(now) != exist.end()) can[MAP[now]] = 1;
    }
    now = b[1];
    for (int j = i; j > 1; j--) {
      now -= a[j];
      if (exist.find(now) != exist.end()) can[MAP[now]] = 1;
    }
    bool ok = 1;
    for (int j = 1; j <= n; j++)
      if (!can[j]) ok = 0;
    if (ans.find(now - a[1]) == ans.end() && ok) ANS++, ans.insert(now - a[1]);
  }
  cout << ANS << endl;
  return 0;
}
