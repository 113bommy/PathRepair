#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
vector<int> getBorder(const string str) {
  int n = str.size();
  vector<int> border(n, -1);
  for (int i = 1, j = -1; i < n; i++) {
    while (j >= 0 && str[i] != str[j + 1]) {
      j = border[j];
    }
    if (str[i] == str[j + 1]) j++;
    border[i] = j;
  }
  return border;
}
int matchPattern(string txt, string pat, const vector<int> border) {
  int freq = 0;
  for (int i = 0, j = -1; i < (int)txt.size(); i++) {
    while (j >= 0 && txt[i] != pat[j + 1]) {
      j = border[j];
    }
    if (txt[i] == pat[j + 1]) {
      j++;
    }
    if (j + 1 == (int)pat.size()) {
      freq++;
      j = border[j];
    }
  }
  return freq;
}
string cut(string s, int p, bool pref = true) {
  if (!pref) {
    reverse(s.begin(), s.end());
  }
  while ((int)s.size() >= p) s.pop_back();
  if (!pref) {
    reverse(s.begin(), s.end());
  }
  return s;
}
const int ms = 210;
string pref[ms], suf[ms];
long long trans[ms];
int bk = 0;
long long getFreq(int n, string pat, long long k) {
  std::vector<long long> f(n + 1, 0);
  if (pat == "0") f[0]++;
  if (pat == "1") f[1]++;
  auto border = getBorder(pat);
  for (int i = 2; i <= n; i++) {
    long long cur = trans[i - 2];
    if (i < bk + 2) {
      string curString = cut(suf[i - 2], (int)pat.size(), false) +
                         cut(pref[i - 1], (int)pat.size());
      cur = matchPattern(curString, pat, border);
    }
    f[i] = f[i - 1] + f[i - 2] + cur;
    if (f[i] > k) return k + 1;
    trans[i] = cur;
  }
  return min(f[n], k + 1);
}
int main() {
  pref[0] = suf[0] = "0";
  pref[1] = suf[1] = "1";
  for (int i = 2; i < ms; i++) {
    pref[i] = cut(pref[i - 2] + pref[i - 1], ms);
    suf[i] = cut(suf[i - 2] + suf[i - 1], ms, false);
    if (pref[i] == pref[i - 2] && suf[i] == suf[i - 1] && bk == 0) bk = i;
  }
  int n, m;
  long long k;
  cin >> n >> k >> m;
  n = min(80, n);
  if (n == 0) {
    cout << "0\n";
    return 0;
  }
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  string ans;
  k--;
  while (k >= 0 && (int)ans.size() < m) {
    if (ans.size() > 0 &&
        suf[n].substr(suf[n].size() - ans.size(), ans.size()) == ans) {
      k--;
    }
    if (k < 0) break;
    ans += '0';
    long long got = getFreq(n, ans, k);
    if (got <= k) {
      ans.back() = '1';
      k -= got;
    }
  }
  cout << ans << endl;
}
