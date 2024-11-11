#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
long long int power(long long int base, long long int exp) {
  long long int res = 1;
  while (exp) {
    if (exp % 2) res *= base;
    base *= base;
    res %= mod;
    base %= mod;
    exp /= 2;
  }
  return res;
}
long long int n, m, k;
string s, t;
long long int lps[maxn];
long long int dp[maxn], dp2[maxn];
void KMPSearch(string pat, string txt) {
  long long int M = int(pat.size());
  long long int N = int(txt.size());
  long long int i = 0;
  long long int j = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      dp[i] = j + 1;
      j++;
      i++;
    }
    if (j == min(M, k)) {
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}
void KMPSearchRev(string pat, string txt) {
  long long int M = int(pat.size());
  long long int N = int(txt.size());
  long long int i = 0;
  long long int j = 0;
  while (i < N) {
    if (pat[j] == txt[i]) {
      dp2[N - i - 1] = j + 1;
      j++;
      i++;
    }
    if (j == min(M, k)) {
      j = lps[j - 1];
    } else if (i < N && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}
void computeLPSArray(string pat, long long int M) {
  long long int len = 0;
  lps[0] = 0;
  long long int i = 1;
  while (i < M) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}
long long int suf[maxn];
set<long long int> adj[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  cin >> s;
  cin >> t;
  computeLPSArray(t, m);
  KMPSearch(t, s);
  for (long long int i = 0; i < n; i++) {
    if (dp[i] == m) {
      long long int st = max(i - k + 1, k + 1);
      cout << "Yes\n";
      cout << 1 << " " << st + 1 << "\n";
      return 0;
    }
  }
  long long int i, j;
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  computeLPSArray(t, m);
  KMPSearchRev(t, s);
  for (i = int(s.size()) - k; i >= k - 1; i--) {
    long long int d = dp2[i];
    while (d != 0 && !suf[d]) {
      adj[i].insert(d);
      suf[d]++;
      d = lps[d - 1];
    }
  }
  bool flag = 0;
  for (i = k - 1; i < int(s.size()) - k; i++) {
    for (auto it : adj[i]) suf[it]--;
    if (suf[m - dp[i]]) {
      cout << "Yes\n";
      flag = 1;
      long long int left = m - dp[i];
      long long int ans = i - k + 1;
      for (i++; i < int(s.size()) - k + 1; i++) {
        if (adj[i].find(left) != adj[i].end()) {
          cout << ans + 1 << " " << i + 1 << "\n";
          return 0;
        }
      }
    }
  }
  assert(!flag);
  cout << "No";
  return 0;
}
