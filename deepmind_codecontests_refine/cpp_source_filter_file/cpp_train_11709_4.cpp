#include <bits/stdc++.h>
using namespace std;
int T, N = 2000, M;
unsigned mat[2000][64];
char buf[999];
int main() {
  scanf("%d", &M);
  for (int i = 0; i < M; i++) {
    scanf("%s", buf);
    int n = strlen(buf);
    reverse(buf, buf + n);
    vector<long long> tmp((n - 1) / 8 + 1, 0);
    for (int i = n; i--;) tmp[i / 8] = tmp[i / 8] * 10 + buf[i] - '0';
    for (int j = 0; j < 250; j++) {
      int v = tmp[0] & 255;
      for (int k = 0; k < 8; k++)
        if (v & (1 << k)) {
          mat[j * 8 + k][i >> 5] ^= (1U << (i & 31));
        }
      for (int k = ((int)(tmp).size()) - 1; k > 0; k--) {
        tmp[k - 1] += (tmp[k] & 255) * (long long)1e8;
        tmp[k] >>= 8;
      }
      tmp[0] >>= 8;
    }
  }
  vector<int> igen;
  for (int i = 0; i < M; i++) {
    int t = ((int)(igen).size());
    bool sw = 0;
    for (int j = t; j < N; j++) {
      if ((bool)(mat[j][i >> 5] & (1U << (i & 31)))) {
        if (t != j) {
          for (int k = 0; k < 64; k++) swap(mat[i][k], mat[j][k]);
        }
        sw = 1;
        break;
      }
    }
    if (!sw) {
      vector<int> arr;
      for (int j = 0; j < t; j++)
        if ((bool)(mat[j][i >> 5] & (1U << (i & 31)))) arr.push_back(igen[j]);
      printf("%d", ((int)(arr).size()));
      for (int t : arr) printf(" %d", t);
      puts("");
      continue;
    }
    igen.push_back(i);
    puts("0");
    for (int j = 0; j < N; j++)
      if (t != j && (bool)(mat[j][i >> 5] & (1U << (i & 31)))) {
        for (int k = 0; k < 64; k++) mat[j][k] ^= mat[t][k];
      }
  }
}
