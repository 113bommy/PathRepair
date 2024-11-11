#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 1000000007;
const long long linf = 0x3f3f3f3f3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
unsigned long long id[500100];
int a[500100];
unsigned long long pref[500100];
int f[500100];
queue<int> q[500100];
map<unsigned long long, unsigned long long> freq;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  uniform_int_distribution<unsigned long long> ri(0ull, 0ull - 1ull);
  for (int i = 1; i <= n; i++) id[i] = ri(rng);
  for (int i = 1; i <= n; i++) {
    f[a[i]]++;
    if (f[a[i]] % 3)
      pref[i] = pref[i - 1] + id[a[i]];
    else
      pref[i] = pref[i - 1] - 2 * id[a[i]];
  }
  unsigned long long ans = 0;
  int left = 0;
  freq[0]++;
  for (int i = 1; i <= n; i++) {
    if (q[a[i]].size() >= 3) {
      int right = q[a[i]].front();
      q[a[i]].pop();
      while (left < right) {
        freq[pref[left]]--;
        left++;
      }
    }
    ans += freq[pref[i]];
    freq[pref[i]]++;
    q[a[i]].push(i);
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ;
  solve();
  return 0;
}
