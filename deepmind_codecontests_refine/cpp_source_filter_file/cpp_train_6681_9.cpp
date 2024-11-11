#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
char tmp[200009], s[200009];
int n, q;
string son;
int dp[200009][2], tree[200009][26], node, cnt[200009];
string arr[200009];
const int BLOK = 500;
void solve(int t) {
  vector<string> v;
  for (int i = 1; i <= q; i++) {
    if (arr[i].size() <= BLOK) {
      int now = 0;
      for (int j = 0; j < arr[i].size(); j++) {
        if (!tree[now][arr[i][j] - 'a']) tree[now][arr[i][j] - 'a'] = ++node;
        now = tree[now][arr[i][j] - 'a'];
      }
      cnt[now]++;
    } else
      v.push_back(arr[i]);
  }
  for (int i = 1; i <= n; i++) {
    int now = 0;
    for (int j = i; j < min(n + 1, i + BLOK); j++) {
      if (!tree[now][s[j] - 'a']) break;
      now = tree[now][s[j] - 'a'];
      if (!t)
        dp[i][0] += cnt[now];
      else
        dp[n - i + 1][1] += cnt[now];
    }
  }
  for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++) {
    string st = (*it) + "#" + son;
    int sz = st.size();
    vector<int> pi(sz);
    for (int i = 1; i < sz; ++i) {
      int j = pi[i - 1];
      while (j > 0 && st[i] != st[j]) j = pi[j - 1];
      if (st[i] == st[j]) ++j;
      pi[i] = j;
    }
    int sa = (*it).size();
    for (int i = 0; i < pi.size(); i++) {
      if (pi[i] == sa) {
        if (!t)
          dp[i - sa * 2 + 1][0]++;
        else
          dp[n - (i - sa * 2 + 1) + 1][1]++;
      }
    }
  }
  for (int i = 0; i <= node; i++) {
    cnt[i] = 0;
    for (int j = 0; j < 26; j++) tree[i][j] = 0;
  }
  node = 0;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) son += s[i];
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%s", tmp);
    arr[i] = string(tmp);
  }
  solve(0);
  for (int i = 1; i <= q; i++) reverse(arr[i].begin(), arr[i].end());
  reverse(s, s + n);
  reverse(son.begin(), son.end());
  solve(1);
  long long ans = 0;
  for (int i = 1; i < n; i++) ans += dp[i][1] * 1LL * dp[i + 1][0];
  printf("%lld\n", ans);
  return 0;
}
