#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long mod1 = 998244353;
const int N = 2e6 + 12;
bool p[N];
long long a[2000], n, c = 0;
vector<int> ans;
void show() {
  cout << (long long)ans.size() << "\n";
  for (auto it : ans) cout << it << " ";
  return;
}
void solve() {
  for (int i = 0; i < N; i++) p[i] = 1;
  p[0] = p[1] = 0;
  for (long long i = 2; i < N; i++)
    if (p[i]) {
      for (long long j = i * i; j < N; j += i) p[j] = 0;
    }
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) c += (a[i] == 1);
  if (c > 1) {
    for (int i = 0; i < c; i++) ans.push_back(1);
    for (int i = c; i < n; i++)
      if (p[a[i] + 1]) {
        ans.push_back(a[c]);
        break;
      }
    show();
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (p[a[i] + a[j]]) {
        ans.push_back(a[i]);
        ans.push_back(a[j]);
        show();
        return;
      }
    }
  }
  ans.push_back(a[0]);
  show();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
