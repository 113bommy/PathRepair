#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const int phi = mod - 1;
int add(int a, int b, int cur_mod) {
  int res = a + b;
  if (res >= cur_mod) res -= cur_mod;
  return res;
}
int mul(int a, int b, int cur_mod) { return (long long int)a * b % cur_mod; }
int bin_pow(int a, int st, int cur_mod) {
  if (st == 0) return 1;
  if (st == 1) return a;
  int res = bin_pow(a, st / 2, cur_mod);
  res = mul(res, res, cur_mod);
  if (st % 2 == 1) res = mul(res, a, cur_mod);
  return res;
}
const int N = (int)1e5 + 10;
string start_str;
int n;
int d[N];
string repl_str[N];
int len[N][10];
int val[N][10];
int main() {
  cin >> start_str;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string cur_str;
    cin >> cur_str;
    d[i] = (int)(cur_str[0] - '0');
    repl_str[i] = cur_str.substr(3, (int)cur_str.length() - 3);
  }
  d[0] = 0;
  repl_str[0] = start_str;
  for (int i = 0; i <= 9; i++) {
    len[n + 1][i] = 1;
    val[n + 1][i] = i;
  }
  for (int i = n; i >= 0; i--) {
    for (int cur_d = 0; cur_d <= 9; cur_d++) {
      if (cur_d != d[i]) {
        len[i][cur_d] = len[i + 1][cur_d];
        val[i][cur_d] = val[i + 1][cur_d];
        continue;
      }
      int sum_len = 0;
      int sum_val = 0;
      reverse(repl_str[i].begin(), repl_str[i].end());
      for (char c : repl_str[i]) {
        int next_d = (int)(c - '0');
        sum_val =
            add(sum_val,
                mul(val[i + 1][next_d], bin_pow(10, sum_len, mod), mod), mod);
        sum_len = add(sum_len, len[i + 1][next_d], phi);
      }
      len[i][cur_d] = sum_len;
      val[i][cur_d] = sum_val;
    }
  }
  cout << val[0][0] << endl;
  return 0;
}
