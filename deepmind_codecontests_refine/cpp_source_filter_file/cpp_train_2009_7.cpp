#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
using namespace chrono;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long int advceil(long long int num, long long int den) {
  return (num % den == 0 ? num / den : num / den + 1);
}
long long int lstbt(long long int val) {
  long long int msk = val & (val - 1);
  return log2(val ^ msk);
}
long long int modmul(long long int a, long long int b) {
  a %= 1000000007;
  b %= 1000000007;
  long long int res = 0;
  while (b > 0) {
    if (b & 1) res = (res + a) % 1000000007;
    a = (a * 2) % 1000000007;
    b /= 2;
  }
  return res;
}
long long int modexpo(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = modmul(res, a);
    a = modmul(a, a);
    b /= 2;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return a == 0 ? b : gcd(b % a, a);
}
vector<long long int> CALCfactor(long long int n) {
  vector<long long int> factor(n + 2, 0);
  for (long long int i = 4; i <= n; i += 2) factor[i] = 2;
  for (long long int j = 3; j <= n; j += 2) {
    if (factor[j]) continue;
    for (long long int i = 2 * j; i <= n; i += j) factor[i] = j;
  }
  return factor;
}
vector<long long int> CALCprimeNUM(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> primeNUM;
  primeNUM.reserve(n + 2);
  for (long long int i = 2; i <= n; i++)
    if (!factor[i]) primeNUM.push_back(i);
  return primeNUM;
}
vector<long long int> CALCprimeFACTOR(long long int n) {
  vector<long long int> factor = CALCfactor(n);
  vector<long long int> ans;
  while (factor[n] != 0) {
    ans.push_back(factor[n]);
    n /= factor[n];
  }
  ans.push_back(n);
  return ans;
}
vector<long long int> unique(vector<long long int> x) {
  sort(x.begin(), x.end());
  set<long long int> s;
  vector<long long int> ans;
  ans.reserve(x.size());
  for (auto elem : x) s.insert(elem);
  for (auto elem : s) ans.push_back(elem);
  return ans;
}
vector<long long int> ZALGO(string s, string pat) {
  long long int lens = pat.length();
  pat += char(36);
  pat += s;
  s = pat;
  vector<long long int> pref(s.length() + 1, 0);
  pref[0] = s.length();
  long long int spt = -1;
  long long int ept = -1;
  long long int processCnt = 0;
  for (long long int i = 1; i < s.length(); i++) {
    bool isdone = false;
    if (i <= ept and i >= spt) {
      if (pref[i - spt] + i <= ept) pref[i] = pref[i - spt], isdone = true;
      processCnt++;
    }
    if (!isdone) {
      long long int ptr = i;
      long long int lo = 0;
      while (s[lo] == s[ptr]) ptr++, lo++, processCnt++;
      if (ept < ptr - 1) {
        spt = i;
        ept = ptr - 1;
      }
      pref[i] = lo;
    }
  }
  vector<long long int> ans;
  ans.reserve(s.length() - lens);
  for (long long int i = lens + 1; i < s.length(); i++) ans.push_back(pref[i]);
  return ans;
}
void spclSort(
    vector<pair<pair<long long int, long long int>, long long int>>& v) {
  long long int n = v.size();
  {
    vector<long long int> cnt(n);
    for (auto elem : v) {
      cnt[elem.first.second]++;
    }
    vector<pair<pair<long long int, long long int>, long long int>> a_new(n);
    vector<long long int> pos(cnt.size());
    pos[0] = 0;
    for (long long int i = 1; i < cnt.size(); i++) {
      pos[i] = cnt[i - 1] + pos[i - 1];
    }
    for (auto elem : v) {
      a_new[pos[elem.first.second]] = elem;
      pos[elem.first.second]++;
    }
    v = a_new;
  }
  {
    vector<long long int> cnt(n, 0);
    for (auto elem : v) {
      cnt[elem.first.first]++;
    }
    vector<pair<pair<long long int, long long int>, long long int>> a_new(n);
    vector<long long int> pos(cnt.size());
    pos[0] = 0;
    for (long long int i = 1; i < cnt.size(); i++) {
      pos[i] = cnt[i - 1] + pos[i - 1];
    }
    for (auto elem : v) {
      a_new[pos[elem.first.first]] = elem;
      pos[elem.first.first]++;
    }
    v = a_new;
  }
}
pair<vector<vector<long long int>>, vector<vector<long long int>>> getOrdering(
    string s) {
  s += char(36);
  vector<vector<long long int>> dp;
  dp.reserve(log2(s.length()) + 3);
  vector<vector<long long int>> dp2;
  dp2.reserve(log2(s.length()) + 3);
  vector<long long int> ordering(s.length()), eqClass(s.length());
  {
    vector<pair<char, long long int>> temp(s.length());
    for (long long int i = 0; i < s.length(); i++) temp[i] = {s[i], i};
    sort(temp.begin(), temp.end());
    for (long long int i = 0; i < temp.size(); i++)
      ordering[temp[i].second] = i;
    eqClass[temp[0].second] = 0;
    for (long long int i = 1; i < temp.size(); i++) {
      if (temp[i].first != temp[i - 1].first)
        eqClass[temp[i].second] = eqClass[temp[i - 1].second] + 1;
      else
        eqClass[temp[i].second] = eqClass[temp[i - 1].second];
    }
    dp.push_back(ordering);
    dp2.push_back(eqClass);
  }
  long long int k = 1;
  while ((1 << (k - 1)) < s.length()) {
    vector<pair<pair<long long int, long long int>, long long int>> arr(
        s.length());
    for (long long int i = 0; i < s.length(); i++) {
      arr[i] = {{eqClass[i], eqClass[(i + (1 << (k - 1))) % s.length()]}, i};
    }
    spclSort(arr);
    for (long long int i = 0; i < s.length(); i++) ordering[arr[i].second] = i;
    eqClass[arr[0].second] = 0;
    for (long long int i = 1; i < s.size(); i++) {
      if (arr[i].first != arr[i - 1].first)
        eqClass[arr[i].second] = eqClass[arr[i - 1].second] + 1;
      else
        eqClass[arr[i].second] = eqClass[arr[i - 1].second];
    }
    dp.push_back(ordering);
    dp2.push_back(eqClass);
    k++;
  }
  return {dp, dp2};
}
vector<long long int> sortOrdering(vector<vector<long long int>> dp) {
  vector<long long int> arr = dp[dp.size() - 1];
  vector<long long int> ans(arr.size());
  long long int cnt = 0;
  for (auto elem : arr) {
    ans[elem] = cnt;
    cnt++;
  }
  return ans;
}
vector<long long int> getLps(string pat) {
  long long int i = 1;
  long long int j = 0;
  vector<long long int> lps(pat.length(), 0);
  lps[0] = 0;
  while (i < pat.length()) {
    if (pat[i] == pat[j])
      lps[i] = j + 1, i++, j++;
    else if (j == 0)
      lps[i] = 0, i++;
    else
      j = lps[j - 1];
  }
  return lps;
}
pair<vector<long long int>, vector<long long int>> getFact(long long int n) {
  vector<long long int> fact(n + 1, 1), invfact(n + 1, 1);
  for (long long int i = 1; i <= n; i++)
    fact[i] = (i * (fact[i - 1])) % 1000000007;
  for (long long int i = 1; i <= n; i++)
    invfact[i] = (modexpo(i, 1000000007 - 2) * invfact[i - 1]) % 1000000007;
  return {fact, invfact};
}
void solve() {
  long long int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;
  if (abs(a3 - a4) > 1) {
    cout << "-1"
         << "\n";
    return;
  }
  string s = "";
  if (a3 > a4 or (a3 == a4 and a1 >= a2))
    for (long long int i = 1; i <= a3; i++) s += "47";
  else
    for (long long int i = 1; i <= a4; i++) s += "74";
  if (a3 == a4 and s[0] == '4') s += "4";
  if (a3 == a4 and s[0] == '7') s += "7";
  long long int acnt = 0, bcnt = 0;
  for (long long int i = 0; i < s.length(); i++)
    acnt += (s[i] == '4'), bcnt += (s[i] == '7');
  if (acnt > a1 or bcnt > a2) {
    cout << "-1"
         << "\n";
    return;
  }
  long long int rema = a1 - acnt;
  long long int remb = a2 - bcnt;
  for (long long int i = 0; i < s.length(); i++)
    if (s[i] == '4') {
      s[i] = '-';
      break;
    }
  for (long long int i = s.length() - 1; i >= 0; i--)
    if (s[i] == '7') {
      s[i] = '$';
      break;
    }
  for (long long int i = 0; i < s.length(); i++) {
    if (s[i] == '$' and (++remb))
      while (remb > 0 and remb--) cout << "7";
    else if (s[i] == '-' and (++rema))
      while (rema > 0 and rema--) cout << "4";
    else
      cout << s[i];
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
}
