#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
long long base[6 * N];
int main() {
  ios::sync_with_stdio(NULL);
  base[0] = 1;
  for (int i = 1; i < N; ++i) {
    base[i] = base[i - 1] * 3 % MOD;
  }
  string word;
  cin >> word;
  int cnt = 0;
  for (int i = 0; i < word.size(); ++i) {
    int idx;
    if (word[i] >= 'A' && word[i] <= 'Z') {
      idx = word[i] - 'A' + 10;
    } else if (word[i] >= 'a' && word[i] <= 'z') {
      idx = word[i] - 'a' + 36;
    } else if (word[i] >= '0' && word[i] <= '9') {
      idx = word[i] - '0';
    } else if (word[i] == '-') {
      idx = 62;
    } else {
      idx = 63;
    }
    for (int j = 0; j < 6; ++j) {
      if (!(idx & (1 << j))) {
        ++cnt;
      }
    }
  }
  long long ans = 1;
  ans = ans * base[cnt] % MOD;
  printf("%I64d\n", ans);
  return 0;
}
