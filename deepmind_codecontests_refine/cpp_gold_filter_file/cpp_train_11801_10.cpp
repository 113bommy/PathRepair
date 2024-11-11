#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000;
const int INF = 0x3f3f3f3f;
map<string, int> mp;
int ans = INF, ansID;
int n;
vector<int> iSeq;
inline int bitCnt(int x) {
  int res = 0;
  while (x) {
    res += x & 1;
    x >>= 1;
  }
  return res;
}
int dp(vector<int>& seq) {
  int m = seq.size();
  seq.insert(seq.begin(), -1);
  static int next[MAXN + 10][15];
  for (int i = 0; i < n; i++) next[m + 1][i] = INF;
  for (int i = m; i >= 0; i--)
    for (int j = 0; j < n; j++) {
      next[i][j] = seq[i] == j ? i : next[i + 1][j];
    }
  static int f[1 << 15][15 * 15];
  memset(f, '?', sizeof(f));
  f[0][0] = 0;
  for (size_t ii = 0; ii < iSeq.size(); ii++) {
    int i = iSeq[ii];
    int iBitCnt = bitCnt(i);
    for (int j = 0; j <= iBitCnt * (iBitCnt - 1) / 2; j++) {
      for (int id = 0; id < n; id++)
        if (i >> id & 1) {
          int cnt = 0;
          for (int k = id + 1; k < n; k++)
            if (i >> k & 1) cnt++;
          if (j >= cnt && f[i ^ (1 << id)][j - cnt] != INF) {
            f[i][j] = min(f[i][j], next[f[i ^ (1 << id)][j - cnt]][id]);
          }
        }
    }
  }
  for (int i = 0; i <= n * (n - 1) / 2; i++)
    if (f[(1 << n) - 1][i] != INF) return i;
  return INF;
}
bool cmp(int x, int y) { return bitCnt(x) < bitCnt(y); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (1 << n); i++) iSeq.push_back(i);
  sort(iSeq.begin(), iSeq.end(), cmp);
  for (int i = 1; i <= n; i++) {
    char tmp[100];
    scanf("%s", tmp);
    mp.insert(make_pair(string(tmp), i - 1));
  }
  int qN;
  scanf("%d", &qN);
  for (int q = 1; q <= qN; q++) {
    int len;
    scanf("%d", &len);
    vector<int> seq;
    for (int i = 0; i < len; i++) {
      char tmp[100];
      scanf("%s", tmp);
      map<string, int>::iterator it = mp.find(tmp);
      if (it != mp.end()) {
        seq.push_back(it->second);
      }
    }
    int res = dp(seq);
    if (res < ans) {
      ans = res;
      ansID = q;
    }
  }
  if (ans == INF)
    puts("Brand new problem!");
  else {
    printf("%d\n", ansID);
    ans = n * (n - 1) / 2 - ans + 1;
    printf("[:");
    for (int i = 0; i < ans; i++) putchar('|');
    printf(":]");
  }
  return 0;
}
