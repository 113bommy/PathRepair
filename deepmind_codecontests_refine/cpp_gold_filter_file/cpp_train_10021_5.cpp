#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int C = 1000001, M = 1000000007;
int seq[C];
ll past_summa[C], exact[C], elems[C];
int main() {
  string s;
  int m, left, right, i, j, n = 0, cur = 0, proper = 0;
  ll res = 0, valid, cur_summa, past;
  cin >> s;
  m = s.size();
  for (i = 0; i < m && s[i] == '0'; i++)
    ;
  if (i == m) {
    printf("%d\n", m);
    return 0;
  }
  left = i;
  for (i = m - 1; i >= 0 && s[i] == '0'; i--)
    ;
  right = i;
  for (i = left + 1; i <= right; i++) {
    if (s[i] == '0')
      cur++;
    else
      seq[n] = cur, cur = 0, n++;
  }
  seq[n] = 0, n++;
  proper = 0, exact[0] = 1, elems[0] = 0;
  for (i = n - 2; i >= 0; i--) {
    valid = seq[i] + 1;
    cur_summa = 0;
    past = 0;
    for (j = proper; j >= 0; j--) {
      if (valid == 0) break;
      cur_summa = (cur_summa + valid * exact[j] +
                   (((seq[i] - elems[j]) > (0)) ? (seq[i] - elems[j]) : (0)) *
                       past_summa[j]) %
                  M;
      if (elems[j] <= seq[i])
        past = (past + past_summa[j] + exact[j]) % M;
      else
        break;
      valid = seq[i] - elems[j];
    }
    elems[j + 1] = seq[i];
    exact[j + 1] = cur_summa % M;
    past_summa[j + 1] = past % M;
    proper = j + 1;
  }
  for (i = 0; i <= proper; i++) res = (res + exact[i] + past_summa[i]) % M;
  printf("%lld\n", (1ll * ((1ll * (left + 1) * (m - right)) % M) * res) % M);
  return 0;
}
