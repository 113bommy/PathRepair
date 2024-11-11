#include <bits/stdc++.h>
using namespace std;
int N, a[1000005], b[1000005];
string ss;
bool IsPrime[1000006];
int mp[1000006], Index, Prime[1000006], L[1000006];
vector<int> stk[1000006];
const int mx = 1e6 + 5;
void Pre() {
  for (int i = 2; i <= mx; i++) {
    if (!IsPrime[i]) {
      mp[i] = i;
      Prime[++Index] = i;
    }
    for (int j = 1; j <= Index && i * Prime[j] <= mx; j++) {
      IsPrime[i * Prime[j]] = true;
      mp[i * Prime[j]] = Prime[j];
      if (i % Prime[j] == 0) break;
    }
  }
}
void Add(int x, int pos) {
  L[pos] = pos;
  while (x > 1) {
    stk[mp[x]].push_back(pos);
    x /= mp[x];
  }
}
void Del(int x, int pos) {
  if (x == 1) {
    L[pos] = pos;
    return;
  }
  L[pos] = pos;
  while (x > 1) {
    if (stk[mp[x]].empty()) {
      L[pos] = 0;
      return;
    }
    L[pos] = min(L[pos], stk[mp[x]].back());
    stk[mp[x]].pop_back();
    x /= mp[x];
  }
}
int main() {
  Pre();
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
  cin >> ss;
  for (int i = 0; i < ss.length(); i++) {
    if (ss[i] == '*')
      Add(a[i + 1], i + 1);
    else
      Del(a[i + 1], i + 1);
  }
  long long ans = 0;
  vector<pair<int, int> > ff;
  for (int i = N; i >= 1; i--) {
    int cnt = 1;
    while (ff.size() > 0 && ff.back().first >= L[i]) {
      cnt += ff.back().second;
      ff.pop_back();
    }
    ff.push_back(make_pair(L[i], cnt));
    if (L[i] == i) ans += (long long)cnt;
  }
  printf("%lld", ans);
  return 0;
}
