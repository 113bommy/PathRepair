#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = 2e5 + 5;
const int M = 5e5 + 5;
int n, q;
int a[N * 2], sp[M], siz;
long long cnt[M], ans;
bool exist[M];
void Precalc() {
  sp[1] = 1;
  for (int i = 2; i < M; i++) {
    if (!sp[i]) {
      sp[i] = i;
      for (int j = 2 * i; j < M; j += i)
        if (!sp[j]) sp[j] = i;
    }
  }
}
void Add(int x) {
  vector<int> p;
  int prev = -1;
  if (x == 1) {
    cnt[x]++;
    ans += siz - 1;
    return;
  }
  while (x > 1) {
    if (sp[x] != prev) {
      p.push_back(sp[x]);
    }
    prev = sp[x];
    x /= sp[x];
  }
  int sz = (int)p.size();
  long long sol = 0;
  for (int i = 1; i < (1 << sz); i++) {
    int k = 1;
    int t = 0;
    for (int j = 0; j < sz; j++) {
      if (i & (1 << j)) k *= p[j], t++;
    }
    if (t % 2 == 1)
      sol += cnt[k];
    else
      sol -= cnt[k];
    cnt[k]++;
  }
  ans += siz - 1 - sol;
}
void Del(int x) {
  vector<int> p;
  int prev = -1;
  if (x == 1) {
    cnt[x]--;
    ans -= siz - 1;
    return;
  }
  while (x > 1) {
    if (sp[x] != prev) {
      p.push_back(sp[x]);
    }
    prev = sp[x];
    x /= sp[x];
  }
  int sz = (int)p.size();
  long long sol = 0;
  for (int i = 1; i < (1 << sz); i++) {
    int k = 1;
    int t = 0;
    for (int j = 0; j < sz; j++) {
      if (i & (1 << j)) k *= p[j], t++;
    }
    if (t % 2 == 1)
      sol += cnt[k] - 1;
    else
      sol -= cnt[k] - 1;
    cnt[k]--;
  }
  ans -= siz - 1 - sol;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  Precalc();
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int x;
    cin >> x;
    if (exist[x]) {
      exist[x] = false;
      Del(a[x]);
      siz--;
    } else {
      siz++;
      exist[x] = true;
      Add(a[x]);
    }
    cout << ans << "\n";
  }
  return 0;
}
