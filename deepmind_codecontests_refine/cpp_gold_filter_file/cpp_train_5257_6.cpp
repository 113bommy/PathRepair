#include <bits/stdc++.h>
using namespace std;
int const SQ = 316 + 4;
int n, q, block[SQ][26], cnt[26], inc_dec[SQ];
string s;
void read_input() {
  cin >> n >> q;
  cin >> s;
}
void build() {
  for (int i = 0; i < n; i++) block[i / SQ][s[i] - 'a']++;
  for (int i = 0; i < SQ; i++) inc_dec[i] = -1;
}
void fill_block_1(int blo, int inc) {
  if (inc == -1) return;
  int b[26], p = (inc ? 0 : 25);
  for (int i = 0; i < 26; i++) b[i] = block[blo][i];
  for (int i = 0; i <= ((n - 1) / SQ == blo ? n % SQ : SQ - 1); i++) {
    while (!b[p]) (inc ? p++ : p--);
    s[blo * SQ + i] = char('a' + p);
    b[p]--;
  }
  inc_dec[blo] = -1;
}
void find_cnt(int L, int R) {
  int b_L = L / SQ, b_R = R / SQ;
  for (int i = b_L + 1; i < b_R; i++)
    for (int k = 0; k < 26; k++) cnt[k] += block[i][k];
  for (int i = L % SQ; i <= (R / SQ == L / SQ ? R % SQ : SQ - 1); i++)
    cnt[s[b_L * SQ + i] - 'a']++;
  if (b_L != b_R)
    for (int i = 0; i <= R % SQ; i++) cnt[s[b_R * SQ + i] - 'a']++;
}
void fill_block_2(char c, int L, int R, int blo, int inc) {
  if (c == 'L') {
    int p = (inc ? 0 : 25);
    for (int i = L % SQ; i <= (L / SQ == R / SQ ? R % SQ : SQ - 1); i++) {
      while (!cnt[p]) (inc ? p++ : p--);
      block[blo][s[blo * SQ + i] - 'a']--;
      s[blo * SQ + i] = char('a' + p);
      block[blo][p]++;
      cnt[p]--;
    }
  } else {
    int p = (inc ? 25 : 0);
    for (int i = R % SQ; i >= 0; i--) {
      while (!cnt[p]) (inc ? p-- : p++);
      block[blo][s[blo * SQ + i] - 'a']--;
      s[blo * SQ + i] = char('a' + p);
      block[blo][p]++;
      cnt[p]--;
    }
  }
}
void sort__(int L, int R, int inc_dec_) {
  int b_L = L / SQ, b_R = R / SQ;
  fill_block_1(b_L, inc_dec[b_L]);
  fill_block_1(b_R, inc_dec[b_R]);
  memset(cnt, 0, sizeof cnt);
  find_cnt(L, R);
  fill_block_2('L', L, R, L / SQ, inc_dec_);
  if (R / SQ != L / SQ) fill_block_2('R', L, R, R / SQ, inc_dec_);
  for (int i = L / SQ + 1; i < R / SQ; i++) inc_dec[i] = inc_dec_;
  int p = (inc_dec_ ? 0 : 25);
  for (int i = L / SQ + 1; i < R / SQ; i++) {
    for (int k = 0; k < 26; k++) block[i][k] = 0;
    int te = 0;
    while (te < SQ) {
      while (!cnt[p]) (inc_dec_ ? p++ : p--);
      int u = min(SQ - te, cnt[p]);
      te += u;
      block[i][p] = u;
      cnt[p] -= u;
    }
  }
}
void write_output() {
  build();
  while (q--) {
    int i, j, k;
    cin >> i >> j >> k;
    i--, j--;
    sort__(i, j, k);
  }
  for (int i = 0; i < SQ; i++) fill_block_1(i, inc_dec[i]);
  cout << s;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input(), write_output();
  return 0;
}
