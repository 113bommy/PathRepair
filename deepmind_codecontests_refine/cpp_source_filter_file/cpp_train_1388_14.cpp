#include <bits/stdc++.h>
using namespace std;
char buf[40];
int N;
long long a[10010];
vector<pair<pair<int, string>, pair<long long, int> > > query;
int ans[30010];
int p[] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
           43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int q[] = {2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23, 29 * 31 * 37 * 41 * 43,
           47 * 53 * 59 * 61, 67 * 71 * 73 * 79, 83 * 89 * 97};
int three[20];
int b[20];
int pre[6][5000000];
int prod[10];
string S;
int Bpow[20];
void precalc(void) {
  int t, i, j;
  three[0] = 1;
  for ((i) = 0; (i) < (int)(14); (i)++) three[i + 1] = three[i] * 3;
  for ((i) = 0; (i) < (int)(three[14]); (i)++) {
    int tmp = i;
    for ((j) = 0; (j) < (int)(14); (j)++) {
      b[j] = tmp % 3;
      tmp /= 3;
    }
    for ((j) = 0; (j) < (int)(14); (j)++)
      if (b[j] == 2) {
        for ((t) = 0; (t) < (int)(5); (t)++)
          pre[t][i] =
              (long long)pre[t][i - three[j]] * pre[t][i - three[j] * 2] % q[t];
        break;
      }
    if (j != 14) continue;
    int mask = 0;
    for ((j) = 0; (j) < (int)(14); (j)++)
      if (b[j] == 1) mask |= (1 << j);
    for ((t) = 0; (t) < (int)(5); (t)++)
      pre[t][i] = ((mask < N) ? a[mask] : 0) % q[t];
  }
}
void dfs(int B, int t, int pos, int digit, int x) {
  if (digit == -1) {
    prod[t] = (long long)prod[t] * (a[x] % q[t]) % q[t];
    return;
  }
  if (S[pos] == '?') {
    int i;
    for (i = 0; i < B; i++) {
      int y = x + Bpow[digit] * i;
      if (y >= N) break;
      dfs(B, t, pos + 1, digit - 1, y);
    }
  } else {
    char ch = S[pos];
    int y = x + Bpow[digit] *
                    ((ch >= '0' && ch <= '9') ? (ch - '0') : (ch - 'A' + 10));
    if (y < N) dfs(B, t, pos + 1, digit - 1, y);
  }
}
void brute_force(int B) {
  int i;
  Bpow[0] = 1;
  for ((i) = 0; (i) < (int)(S.length()); (i)++) Bpow[i + 1] = Bpow[i] * B;
  for ((i) = 0; (i) < (int)(5); (i)++) prod[i] = 1;
  for ((i) = 0; (i) < (int)(5); (i)++) dfs(B, i, 0, S.length() - 1, 0);
}
void calc(int B, string s) {
  int count_zero = 0;
  int i;
  for ((i) = 0; (i) < (int)(s.length()); (i)++)
    if (s[i] == '0') count_zero++;
  if (B != 2) {
    S = s;
    brute_force(B);
    return;
  }
  int sum = 0;
  for ((i) = 0; (i) < (int)(14); (i)++) {
    if (s[i] == '1') sum += three[13 - i];
    if (s[i] == '?') sum += three[13 - i] * 2;
  }
  for ((i) = 0; (i) < (int)(5); (i)++) prod[i] = pre[i][sum];
}
int min_divisor(long long C) {
  int i, j;
  int a[6] = {0, 9, 14, 18, 22, 25};
  for ((i) = 0; (i) < (int)(5); (i)++) {
    long long tmp = C + prod[i];
    for (j = a[i]; j < a[i + 1]; j++)
      if (tmp % p[j] == 0) return p[j];
  }
  return -1;
}
int main(void) {
  int Q, i, j;
  scanf("%d", &N);
  for ((i) = 0; (i) < (int)(N); (i)++) scanf("%I64d", &a[i]);
  precalc();
  scanf("%d", &Q);
  for ((i) = 0; (i) < (int)(Q); (i)++) ans[i] = -1;
  for ((j) = 0; (j) < (int)(Q); (j)++) {
    int B;
    long long C;
    scanf("%d", &B);
    scanf("%s", buf);
    scanf("%I64d", &C);
    int maxlen = 0;
    int power = 1;
    while (power < 10000) {
      power *= B;
      maxlen++;
    }
    bool bad = false;
    string s = buf;
    if (s.length() > maxlen) {
      for ((i) = 0; (i) < (int)(s.length() - maxlen); (i)++)
        if (s[i] != '0' && s[i] != '?') bad = true;
      s = s.substr(s.length() - maxlen);
    } else if (s.length() < maxlen) {
      string t;
      for ((i) = 0; (i) < (int)(maxlen - s.length()); (i)++) t += '0';
      s = t + s;
    }
    if (bad) {
      for ((i) = 0; (i) < (int)(25); (i)++)
        if ((C + 1) % p[i] == 0) {
          ans[j] = p[i];
          break;
        }
    } else {
      query.push_back(make_pair(make_pair(B, s), make_pair(C, j)));
    }
  }
  sort(query.begin(), query.end());
  for ((i) = 0; (i) < (int)(query.size()); (i)++) {
    if (i == 0 || query[i].first != query[i - 1].first)
      calc(query[i].first.first, query[i].first.second);
    ans[query[i].second.second] = min_divisor(query[i].second.first);
  }
  for ((i) = 0; (i) < (int)(Q); (i)++) printf("%d\n", ans[i]);
  return 0;
}
