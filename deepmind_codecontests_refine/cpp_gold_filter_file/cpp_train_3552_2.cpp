#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 252;
int cnt[N][N][26];
int contains2odds(int j1, int j2, int i) {
  int cn = 0;
  for (int k = 0; k < 26; k++) {
    if ((cnt[i][j2][k] - (j1 ? cnt[i][j1 - 1][k] : 0)) % 2) cn++;
  }
  return cn > 1;
}
long long hsh(const vector<int>& freq) {
  long long res = 0;
  for (int i = 0; i < 26; i++) {
    res *= 37;
    res += (freq[i] + 1);
  }
  return res;
}
vector<int> get_freq(int j1, int j2, int i) {
  vector<int> res(26);
  for (int k = 0; k < 26; k++) {
    res[k] = cnt[i][j2][k] - (j1 ? cnt[i][j1 - 1][k] : 0);
  }
  return res;
}
int count_palindromes(const vector<long long>& s) {
  int n = s.size();
  vector<int> d1(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  vector<int> d2(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
      k++;
    }
    d2[i] = k--;
    if (i + k > r) {
      l = i - k - 1;
      r = i + k;
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) res += d1[i] + d2[i];
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  string grid[n];
  for (int i = 0; i < n; i++) cin >> grid[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 26; k++) {
        if (j) cnt[i][j][k] = cnt[i][j - 1][k];
      }
      cnt[i][j][grid[i][j] - 'a']++;
    }
  }
  long long res = 0;
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      vector<long long> s;
      for (int k = 0; k < n; k++) {
        if (contains2odds(i, j, k)) {
          res += count_palindromes(s);
          s.clear();
        } else {
          s.push_back(hsh(get_freq(i, j, k)));
        }
      }
      res += count_palindromes(s);
    }
  }
  cout << res << endl;
  return 0;
}
