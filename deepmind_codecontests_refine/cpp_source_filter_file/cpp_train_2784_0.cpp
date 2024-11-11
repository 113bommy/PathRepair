#include <bits/stdc++.h>
using namespace std;
vector<long long> fact(19);
vector<int> f_cnt(10);
void precalc() {
  fact[0] = 1;
  for (int i = 1; i < 19; i++) fact[i] = fact[i - 1] * i;
}
int main() {
  set<vector<int> > st;
  long long ans(0);
  string s;
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) f_cnt[s[i] - '0']++;
  precalc();
  long long mask = 1 << n;
  for (int i = 0; i < mask; i++) {
    vector<int> cnt(10);
    int k(0);
    for (int j = 0; j < n; j++)
      if ((i & (1 << j)) != 0) {
        k++, cnt[s[n - j - 1] - '0']++;
      }
    long long fz(1);
    bool flag = 0;
    for (int j = 0; j < 10; j++)
      if (f_cnt[j] != 0 && cnt[j] == 0) flag = 1;
    if (flag || st.find(cnt) != st.end()) continue;
    st.insert(cnt);
    for (int j = 0; j < 10; j++) fz *= fact[cnt[j]];
    ans += fact[k] / fz;
    if (cnt[0] > 0) {
      k--;
      cnt[0]--;
      fz = 1;
      for (int j = 0; j < 10; j++) fz *= fact[cnt[j]];
      ans -= fact[k] / fz;
    }
  }
  cout << ans;
}
