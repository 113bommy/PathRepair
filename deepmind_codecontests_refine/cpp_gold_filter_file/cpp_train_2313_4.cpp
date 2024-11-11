#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 5;
const long long base = 1e18;
long long ans1, ans2, ans3;
long long ans26, sum;
int w[maxn], nex[maxn], fa[maxn];
char s[maxn];
vector<int> sta;
map<int, int> cnt;
int query(int pos) { return w[*lower_bound(sta.begin(), sta.end(), pos)]; }
void print() {
  if (ans1 == 0)
    cout << ans2 << '\n';
  else {
    cout << ans1 << setw(18) << setfill('0') << ans2 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  cin >> s[0] >> w[0];
  ans26 = w[0] % 26;
  ans2 = ans3 = w[0];
  print();
  sta.emplace_back(0);
  for (int i = 1, j = 0; i < n; ++i) {
    cin >> s[i] >> w[i];
    s[i] = (s[i] - 'a' + ans26) % 26 + 'a';
    w[i] ^= ans3;
    while (j > 0 && s[j] != s[i]) j = nex[j];
    if (s[i] == s[j]) ++j;
    nex[i + 1] = j;
    if (s[i] == s[nex[i]])
      fa[i] = fa[nex[i]];
    else
      fa[i] = nex[i];
    for (int k = i; k > 0;) {
      if (s[i] == s[k])
        k = fa[k];
      else {
        int v = query(i - k);
        --cnt[v], sum -= v;
        if (cnt[v] == 0) cnt.erase(v);
        k = nex[k];
      }
    }
    if (s[0] == s[i]) {
      ++cnt[w[i]];
      sum += w[i];
    }
    while (!sta.empty() && w[i] <= w[sta.back()]) sta.pop_back();
    sta.emplace_back(i);
    int num = 0;
    for (auto it = cnt.upper_bound(w[i]); it != cnt.end();) {
      sum -= (1ll * (it->first - w[i]) * it->second);
      num += it->second;
      auto j = std::next(it);
      cnt.erase(it);
      it = j;
    }
    cnt[w[i]] += num;
    long long res = w[sta[0]] + sum;
    ans2 += res;
    if (ans2 >= base) ++ans1, ans2 -= base;
    ans26 = (ans26 + res) % 26;
    ans3 = (ans3 + res) & ((1 << 30) - 1);
    print();
  }
  return 0;
}
