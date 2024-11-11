#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int INF = (int)1e9;
const long long IINF = 1LL << 62;
const int maxn = 10000005;
const int BSIZE = 20;
int base[BSIZE];
int size = 0;
const int N = 1e5 + 10;
int a[N], n;
int q;
int power[N];
vector<int> q_at[N];
int ans[N];
vector<pair<int, int>> vec(N);
void insertvector(int mask) {
  for (int i = 0; i < BSIZE; i++) {
    if ((mask & (1 << i)) == 0) continue;
    if (!base[i]) {
      base[i] = mask;
      size++;
      return;
    }
    mask ^= base[i];
  }
}
bool checkxor(int mask) {
  for (int i = 0; i < BSIZE; i++) {
    if ((mask & (1 << i)) == 0) continue;
    if (!base[i]) return false;
    mask ^= base[i];
  }
  return true;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) {
    cin >> vec[i].first >> vec[i].second;
    q_at[vec[i].first].push_back(i);
  }
  power[0] = 1;
  for (int i = 1; i < N; i++) power[i] = (power[i - 1] * 2LL) % 1000000007;
  for (int i = 1; i <= n; i++) {
    insertvector(a[i]);
    for (auto it : q_at[i]) {
      if (checkxor(vec[it].second)) {
        ans[it] = power[i - size];
      }
    }
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
