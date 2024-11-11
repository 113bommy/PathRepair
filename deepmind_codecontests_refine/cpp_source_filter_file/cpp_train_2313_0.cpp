#include <bits/stdc++.h>
using namespace std;
const int N = 600005, MASK = (1 << 30) - 1;
const long long P = 1e18;
int n, w[N], nxt[N], anc[N];
int ans26, ansM;
char s[N];
pair<long long, long long> ans;
map<int, int> mp;
void ad(long long x) {
  (ans26 += x % 26) %= 26;
  (ansM += x & MASK) &= MASK;
  if ((ans.first += x) >= P) {
    ans.first -= P;
    ++ans.second;
  }
}
void out() {
  if (ans.second)
    printf("%lld%0lld\n", ans.second, ans.first);
  else
    printf("%lld\n", ans.first);
}
vector<int> st;
void ps(int x) {
  while (((int)(st).size()) && w[x] <= w[st.back()]) st.pop_back();
  st.push_back(x);
}
int main() {
  scanf("%d", &n);
  while (!islower(s[1] = getchar()))
    ;
  scanf("%d", &w[1]);
  int j = 0;
  st.push_back(1);
  ad(w[1]);
  out();
  long long sum = 0;
  for (int i = (2); i <= (n); ++i) {
    while (!islower(s[i] = getchar()))
      ;
    s[i] = (s[i] - 'a' + ans26) % 26 + 'a';
    scanf("%d", &w[i]);
    w[i] ^= ansM;
    while (j && s[j + 1] != s[i]) j = nxt[j];
    if (s[j + 1] == s[i]) ++j;
    nxt[i] = j;
    if (s[i] == s[nxt[i - 1] + 1]) {
      anc[i] = anc[nxt[i - 1] + 1];
    } else {
      anc[i] = nxt[i - 1] + 1;
    }
    for (int k = i; k > 1;) {
      if (s[k] == s[i]) {
        k = anc[k];
      } else {
        int tem = w[*lower_bound(st.begin(), st.end(), i - k + 1)];
        sum -= tem;
        --mp[tem];
        if (mp[tem] == 0) mp.erase(tem);
        k = nxt[k - 1] + 1;
      }
    }
    ps(i);
    if (s[i] == s[1]) {
      sum += w[i];
      ++mp[w[i]];
    }
    int tt = 0;
    for (auto it = mp.lower_bound(w[i]); it != mp.end();) {
      sum -= 1LL * (it->first - w[i]) * it->second;
      tt += it->second;
      mp.erase(it++);
    }
    mp[w[i]] += tt;
    ad(w[st[0]] + sum);
    out();
  }
  return 0;
}
