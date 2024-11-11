#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int BASE = 1e9 + 7;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int N = 2e5 + 1;
pair<int, int> a[N];
vector<int> V;
int n, Bit[N], cnt[N];
long long ans = 0;
bool comp(pair<int, int> A, pair<int, int> B) {
  return ((A.second == B.second) ? (A.first < B.first) : (A.second < B.first));
}
void Update(int p, int v) {
  for (; p <= n; p += p & -p) {
    Bit[p] += v;
  }
}
int Get(int p) {
  int ans = 0;
  for (; p > 0; p -= p & -p) {
    ans += Bit[p];
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  set<int> S;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    S.insert(a[i].first);
  }
  sort(a + 1, a + 1 + n, comp);
  for (__typeof(S.begin()) it = S.begin(); it != S.end(); it++)
    V.push_back(*it);
  for (int i = 0; i < V.size(); i++) {
    Update(i + 1, 1);
  }
  for (int i = 1; i <= n; i++) {
    int k = lower_bound(V.begin(), V.end(), a[i].first) - V.begin() + 1;
    a[i].first = k;
    cnt[k]++;
  }
  for (int i = 1; i <= n; i++) {
    int x = a[i].first;
    int y = a[i].second;
    int left, right;
    right = Get(n) - Get(x);
    if (y != a[i - 1].second) {
      left = Get(x - 1);
    } else {
      left = Get(x - 1) - Get(a[i - 1].first);
    }
    ans += 1ll * (left + 1) * (right + 1);
    cnt[x]--;
    if (cnt[x] == 0) Update(x, -1);
  }
  cout << ans;
  return 0;
}
