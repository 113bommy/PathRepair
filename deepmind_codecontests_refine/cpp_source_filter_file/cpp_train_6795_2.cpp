#include <bits/stdc++.h>
using namespace std;
const int N = 0 ? 100 : 5e5 + 7;
int n;
int a[N];
unsigned long long hc[N];
unsigned long long h[N];
int cnt[N];
vector<int> arr[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  mt19937_64 rnd(239);
  for (int x = 0; x < n; ++x) {
    hc[x] = rnd();
  }
  map<unsigned long long, int> r;
  int start = -1;
  ++r[0];
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    h[i] = (i == 0 ? 0 : h[i - 1]) - cnt[a[i]] * hc[a[i]];
    cnt[a[i]] = (cnt[a[i]] + 1) % 3;
    h[i] += cnt[a[i]] * hc[a[i]];
    ++r[h[i]];
    arr[a[i]].push_back(i);
    if (arr[a[i]].size() > 3) {
      while (start <= arr[a[i]][arr[a[i]].size() - 4]) {
        --r[start == -1 ? 0 : h[start]];
        ++start;
      }
    }
    ans += r[h[i]] - 1;
  }
  cout << ans << '\n';
  return 0;
}
