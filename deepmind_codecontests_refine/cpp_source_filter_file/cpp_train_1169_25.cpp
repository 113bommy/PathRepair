#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, logn = 36, lim = 12;
int N, M, cnt[1 << lim][logn - lim], z;
long long arr[maxn], bss[logn], ans[logn], pw = 1;
vector<long long> l, r;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    z += arr[i] == 0;
  }
  for (int i = 1; i <= N; i++) {
    long long curr = arr[i];
    for (int k = M - 1; k >= 0; k--) {
      if (!(curr & (1LL << k))) continue;
      if (!bss[k]) bss[k] = curr;
      curr ^= bss[k];
    }
  }
  for (int i = 0; i < M; i++) {
    if (!bss[i]) continue;
    if (bss[i] > (1 << lim))
      r.push_back(bss[i]);
    else
      l.push_back(bss[i]);
  }
  for (int i = l.size() + r.size(); i < N; i++) pw = pw * 2 % 998244353;
  for (int i = 0; i < (1 << r.size()); i++) {
    long long num = 0;
    for (int k = 0; k < r.size(); k++) {
      if (!(i & (1 << k))) continue;
      num ^= r[k];
    }
    cnt[num & ((1LL << lim) - 1)][__builtin_popcountll(num >> lim)]++;
  }
  for (int i = 0; i < (1 << l.size()); i++) {
    long long num = 0;
    for (int k = 0; k < l.size(); k++) {
      if (!(i & (1 << k))) continue;
      num ^= l[k];
    }
    for (int m = 0; m < (1 << lim); m++) {
      int nxt = __builtin_popcountll(m ^ num);
      for (int v = 0; v <= M - nxt; v++) {
        ans[nxt + v] += cnt[m][v];
        if (ans[nxt + v] >= 998244353) ans[nxt + v] -= 998244353;
      }
    }
  }
  for (int i = 0; i <= M; i++) cout << ans[i] * pw % 998244353 << " ";
}
