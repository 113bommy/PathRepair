#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 1050000;
int C[N];
inline int lowbit(int x) { return x & (-x); }
void add(int x, int t) {
  for (; x < N; C[x] += t, x += lowbit(x))
    ;
}
int sum(int x) {
  int res = 0;
  for (; x; res += C[x], x ^= lowbit(x))
    ;
  return res;
}
vector<int> vec;
long long cnt[30];
long long tot[30];
int v[N];
int n, m;
void get(int d) {
  cnt[d] = 0;
  tot[d] = 0;
  int x = 1 << d;
  int top = 1 << n;
  for (int i = 0; i < top; i += x) {
    for (int j = 0; j < x; ++j) {
      if (j * 2 >= x) {
        tot[d] += sum(v[i + j] - 1);
        cnt[d] += x / 2 - sum(v[i + j]);
      } else {
        add(v[i + j], 1);
      }
    }
    for (int j = 0; j * 2 < x; ++j) add(v[i + j], -1);
  }
  tot[d] += cnt[d];
}
void get_cnt() {
  cnt[0] = 0;
  tot[0] = 0;
  for (int i = 1; i <= n; ++i) {
    get(i);
  }
}
long long Ans(int q) {
  for (int i = 1; i <= q; ++i) cnt[i] = tot[i] - cnt[i];
  long long res = 0;
  for (int i = 1; i <= n; ++i) res += cnt[i];
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int top = 1 << n;
  for (int i = 0; i < top; ++i) {
    cin >> v[i];
    vec.push_back(v[i]);
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < top; ++i) {
    v[i] = lower_bound(vec.begin(), vec.end(), v[i]) - vec.begin() + 1;
  }
  memset(cnt, 0, sizeof(cnt));
  get_cnt();
  int q;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> q;
    cout << Ans(q) << endl;
  }
}
