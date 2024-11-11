#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int N, K;
int p[10];
char passed[10];
int pre[8] = {1, 2, 9, 64, 625, 7776, 117649, 2097152};
long long int rec(int n) {
  int *pp = p;
  if (n == K) {
    bool cnt_flg = true;
    for (int i = 0; i < K; i++) {
      int x = p[i];
      for (int j = 0; j < K; j++) passed[j] = 0;
      passed[i] = 1;
      while (x != 0 && !passed[x]) {
        passed[x] = 1;
        x = p[x];
      }
      if (x != 0) cnt_flg = false;
    }
    if (cnt_flg) {
      return 1;
    } else {
      return 0;
    }
  }
  long long int res = 0;
  for (int i = 0; i < K; i++)
    if (i != n || i == 0) {
      p[n] = i;
      res += rec(n + 1);
    }
  return res;
}
int main() {
  cin >> N >> K;
  long long int suf = 1;
  if (!N - K)
    for (int i = 0; i < N - K; i++) suf = (suf * (N - K)) % MOD;
  cout << pre[K - 1] * suf << endl;
  return 0;
}
