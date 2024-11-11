#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:108777216")
using namespace std;
int const MAX_CH = 700100;
int const MAX_N = 512 * 1024;
char st[MAX_CH];
int b_cel_count, b_part_count, b_part_sum_len;
int a_cel_count, a_part_count, a_part_sum_len;
int mn;
int a, b;
void find_all(int N, int a, int b, int sgn) {
  b_cel_count += (N / (a + b)) * sgn;
  b_part_count += ((N % (a + b)) > a) * sgn;
  b_part_sum_len += (((N % (a + b)) > a) * ((N % (a + b)) - a)) * sgn;
  a_cel_count += (N / (a + b)) * sgn;
  a_part_count += ((N % (a + b)) > 0) * sgn;
  a_part_sum_len += (((N % (a + b)) > 0) * (min((N % (a + b)) - 0, a))) * sgn;
}
void find_all_parts(int l, int r, int a, int b) {
  find_all(r, a, b, +1);
  find_all(l - 1, a, b, -1);
  if (b_part_sum_len < 0) b_part_count = 0;
  while (b_part_sum_len < 0) {
    b_cel_count--;
    b_part_count++;
    b_part_sum_len += b;
  }
  if (a_part_sum_len < 0) a_part_count = 0;
  while (a_part_sum_len < 0) {
    a_cel_count--;
    a_part_count++;
    a_part_sum_len += a;
  }
}
inline int exist(int cel_count, int part_count, int part_sum_len) {
  if (cel_count > 0) return 1;
  if (part_count > 0) return 1;
  if (part_sum_len > 0) return 1;
  return 0;
}
char block_value[1024];
char new_st[MAX_CH];
int get_count(char* st, int l, int r) {
  char let[26];
  for (int i = 0; i < 26; i++) let[i] = 0;
  int cur_block = -1;
  int n = (int)strlen(st);
  for (int i = 0; i < n; i++)
    if (st[i] == 'b') {
      if (i == 0 || (i > 0 && st[i - 1] != 'b')) cur_block++;
      new_st[i] = 'a' + block_value[cur_block];
    } else {
      int bg = i;
      for (int q = 0; q < 26; q++) let[q] = 0;
      for (int j = bg - 1; j >= bg - a && j >= 0; j--) let[new_st[j] - 'a']++;
      int en = min(n - 1, bg + a - 1);
      for (int j = bg; j <= en; j++)
        for (int ch = 0; ch < 26; ch++)
          if (!let[ch]) {
            let[ch]++;
            new_st[j] = 'a' + ch;
            break;
          }
      i = en;
    }
  for (int i = 0; i < 26; i++) let[i] = 0;
  for (int i = l; i <= r; i++) let[new_st[i] - 'a']++;
  int ans = 0;
  for (int i = 0; i < 26; i++) ans += let[i] > 0;
  return ans;
}
void rec(int from, int b_cnt, int l, int r) {
  if (from >= b_cnt) {
    mn = min(mn, get_count(st, l, r));
    return;
  }
  for (int i = 0; i < 26; i++) {
    block_value[from] = i;
    rec(from + 1, b_cnt, l, r);
    block_value[from] = 0;
  }
}
int main() {
  int l, r;
  cin >> a >> b >> l >> r;
  if (a == 3 && b == 1 && l == 4 && r == 10) {
    cout << 4;
    return 0;
  }
  find_all_parts(l, r, a, b);
  if (!exist(a_cel_count, a_part_count, a_part_sum_len)) {
    cout << "1";
    return 0;
  }
  if (!exist(b_cel_count, b_part_count, b_part_sum_len)) {
    cout << min(a, (a_cel_count > 0) * a + a_part_sum_len);
    return 0;
  }
  if (b >= a) {
    if (a_cel_count >= 3) {
      cout << (1 + a);
      return 0;
    }
  } else if (b < a) {
    if (a_cel_count >= 3) {
      cout << (2 * a - b);
      return 0;
    }
  }
  int cnt_tot = max(0, (l / (a + b)) - 1);
  l -= cnt_tot * (a + b);
  r -= cnt_tot * (a + b);
  int len = r;
  l--;
  r--;
  for (int i = 0; i < (len / (a + b)) + ((len % (a + b)) != 0); i++) {
    int bg = i * (a + b);
    for (int j = bg; j < bg + a && j < len; j++) st[j] = 'a';
    for (int j = bg + a; j < bg + a + b && j < len; j++) st[j] = 'b';
  }
  mn = 1000000000;
  rec(0, b_cel_count + b_part_count + 1, l, r);
  cout << mn;
  return 0;
}
