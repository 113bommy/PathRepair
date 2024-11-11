#include <bits/stdc++.h>
using namespace std;
int mod[3] = {1000000007, 1000000009, 1500450271};
int B[3] = {100019, 223007, 100003};
int pw[3][100001];
int hsh[3][1000001];
int cid[1000001];
bool cmp(int a, int b) {
  if (hsh[0][a] == hsh[0][b]) {
    if (hsh[1][a] == hsh[1][b]) return hsh[2][a] < hsh[2][b];
    return hsh[1][a] < hsh[1][b];
  }
  return hsh[0][a] < hsh[0][b];
}
int fact[1000001];
int main() {
  for (int i = 0; i < 3; i++) {
    pw[i][0] = 1;
    for (int j = 1; j <= 100000; j++)
      pw[i][j] = (((long long)pw[i][j - 1]) * B[i]) % mod[i];
  }
  int N, M, k, g;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &g);
      g--;
      for (int c = 0; c < 3; c++)
        hsh[c][g] = (hsh[c][g] + (long long)pw[c][i]) % mod[i];
    }
  }
  for (int i = 0; i < M; i++) cid[i] = i;
  sort(cid, cid + M, cmp);
  fact[0] = 1;
  for (int i = 1; i <= M; i++)
    fact[i] = (((long long)fact[i - 1]) * i) % mod[0];
  int lst = -1;
  int ans = 1;
  for (int i = 0; i < M; i++) {
    if (i == M - 1 || cmp(cid[i], cid[i + 1])) {
      ans = (ans * ((long long)fact[i - lst])) % mod[0];
      lst = i;
    }
  }
  printf("%d\n", ans);
}
