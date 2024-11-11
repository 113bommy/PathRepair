#include <bits/stdc++.h>
using namespace std;
const int base = 311;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277,
                   (int)1e9 + 9277};
string s, t;
int pw[3][500500];
int cnt_s[2];
int cnt_t[2];
void init() {
  memset(pw, 0, sizeof pw);
  memset(cnt_s, 0, sizeof cnt_s);
  memset(cnt_t, 0, sizeof cnt_t);
  for (int i = 0; i < 3; i++) {
    pw[i][0] = 1;
    for (int j = 1; j < 500500; j++) {
      pw[i][j] = 1LL * pw[i][j - 1] * base % MOD[i];
    }
  }
}
struct Hash {
  int value[3];
  Hash() { memset(value, 0, sizeof value); }
  Hash(char c) {
    for (int i = 0; i < 3; i++) value[i] = c;
  }
  Hash operator+(const Hash &h) const {
    Hash res;
    for (int i = 0; i < 3; i++) {
      res.value[i] = value[i] + h.value[i];
      if (res.value[i] >= MOD[i]) res.value[i] -= MOD[i];
    }
    return res;
  }
  Hash operator-(const Hash &h) const {
    Hash res;
    for (int i = 0; i < 3; i++) {
      res.value[i] = value[i] - h.value[i];
      if (res.value[i] < MOD[i]) res.value[i] += MOD[i];
    }
    return res;
  }
  Hash operator*(int k) const {
    Hash res;
    for (int i = 0; i < 3; i++)
      res.value[i] = 1LL * value[i] * pw[i][k] % MOD[i];
    return res;
  }
  bool operator==(const Hash &h) const {
    for (int i = 0; i < 3; i++)
      if (value[i] != h.value[i]) return false;
    return true;
  }
};
Hash hS[500500], hT[500500];
Hash gethash(int l, int r) { return (hT[r] - hT[l - 1]) * (500500 - l); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  init();
  cin >> s >> t;
  s = ' ' + s;
  t = ' ' + t;
  for (int i = 1; i < (int)t.size(); i++) {
    hT[i] = hT[i - 1] + Hash(t[i]) * i;
    cnt_t[t[i] - '0']++;
  }
  for (int i = 1; i < (int)s.size(); i++) {
    cnt_s[s[i] - '0']++;
  }
  if (cnt_s[0] < cnt_t[0] || cnt_s[1] < cnt_t[1])
    return cout << s.substr(1, (int)s.size() - 1), 0;
  int pos = 1;
  for (int i = 1; i < (int)t.size() - 1; i++) {
    if (gethash(1, i) == gethash((int)t.size() - i, (int)t.size() - 1))
      pos = i + 1;
  }
  if (pos == t.size()) pos = 1;
  bool ok = 1;
  for (int i = 1, j = 1; i < (int)s.size(); i++) {
    if (j == (int)t.size()) {
      if (ok && i >= (int)t.size())
        j = pos;
      else
        j = 1;
      ok = 1;
    }
    if (cnt_s[t[j] - '0'] == 0) {
      int x = t[j] - '0';
      x ^= 1;
      s[i] = x + '0';
      cnt_s[x]--;
    } else {
      s[i] = t[j];
      cnt_s[t[j] - '0']--;
    }
    j++;
  }
  cout << s.substr(1, (int)s.size() - 1);
  return 0;
}
