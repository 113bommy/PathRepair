#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 100010;
int a[N];
vector<int> f[N];
void go() {
  long long n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 2; i < N; i++) {
    if (f[i].size()) continue;
    for (int j = i; j < N; j += i) f[j].push_back(i);
  }
  int freq[N] = {0};
  for (int i = 0; i < n; i++) {
    int m = 0;
    for (auto x : f[a[i]]) {
      m = max(m, freq[x] + 1);
    }
    freq[a[i]] = m;
    for (auto x : f[a[i]]) {
      freq[x] = m;
    }
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = max(freq[a[i]], ans);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t = 1;
  cout << fixed << setprecision(9);
  while (t--) {
    go();
  }
}
