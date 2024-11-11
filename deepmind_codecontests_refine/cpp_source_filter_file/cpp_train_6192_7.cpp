#include <bits/stdc++.h>
using namespace std;
const int N = 312;
const int MASK = 1024;
const int INF = 1e9;
int n;
int chosen;
int l[N], c[N], r[N];
bool used[N][MASK];
int state[N][MASK];
int ans;
vector<int> divisors[N];
int mask;
int recurse(int curr, int mask, int rem) {
  if (curr == chosen) return recurse(curr + 1, mask, rem);
  if (rem == 0) return 0;
  if (curr > n) return INF;
  if (used[curr][mask]) return state[curr][mask];
  int i, new_rem = rem, new_mask = mask, ans = recurse(curr + 1, mask, rem);
  for (i = 0; i < divisors[chosen].size(); i++) {
    if (r[curr] % divisors[chosen][i] != 0) {
      if (new_mask & (1 << i)) {
        new_mask ^= (1 << i);
        new_rem--;
      }
    }
  }
  ans = min(ans, c[curr] + recurse(curr + 1, new_mask, new_rem));
  used[curr][mask] = true;
  state[curr][mask] = ans;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, sakjklasda;
  ans = INF;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> l[i];
  for (i = 1; i <= n; i++) r[i] = l[i];
  for (i = 1; i <= n; i++) cin >> c[i];
  for (i = 1; i <= n; i++) {
    sakjklasda = 2;
    while (sakjklasda <= sqrt(l[i])) {
      if (l[i] % sakjklasda == 0) {
        divisors[i].push_back(sakjklasda);
        while (l[i] % sakjklasda == 0) l[i] /= sakjklasda;
      }
      sakjklasda++;
    }
    if (l[i]) divisors[i].push_back(l[i]);
  }
  for (chosen = 1; chosen <= n; chosen++) {
    mask = 0;
    for (i = 0; i < divisors[chosen].size(); i++) mask |= (1 << i);
    memset(used, 0, sizeof(used));
    ans = min(ans, c[chosen] + recurse(1, mask, divisors[chosen].size()));
  }
  if (ans < INF)
    cout << ans << '\n';
  else
    cout << -1 << '\n';
  return 0;
}
