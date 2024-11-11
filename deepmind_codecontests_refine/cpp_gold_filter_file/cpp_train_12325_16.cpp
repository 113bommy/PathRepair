#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
int v[MAXN], n, k;
int vec[1000100][12];
bool vis[1000100];
void crivo() {
  for (int i = 1; i <= 1000001; i++) {
    set<int> s;
    for (int j = 0; j <= 1000000; j += i) {
      for (int t = 1; t <= 11; t++) {
        int at = vec[j][t];
        if (at == -1) break;
        s.insert(at);
        if (s.size() > 2 * k) {
          vis[i] = true;
          break;
        }
      }
      if (vis[i] == true) break;
    }
    if (vis[i] == true) continue;
    int q = 0;
    unordered_map<int, int> mp;
    for (auto j : s) mp[v[j] % i]++;
    for (auto j : mp) q += j.second - 1;
    if (q > k) vis[i] = true;
    if (vis[i] == false) {
      printf("%d\n", i);
      return;
    }
  }
}
vector<int> vet[1000100];
int cnt[1000100];
int main() {
  memset(cnt, 0, sizeof cnt);
  memset(vec, -1, sizeof vec);
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int h = abs(v[i] - v[j]);
      if (cnt[h] > 10) continue;
      vec[h][cnt[h] + 1] = i, cnt[h]++;
    }
  }
  crivo();
}
