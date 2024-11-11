#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char word[101];
int mem[101][2501] = {};
int main() {
  for (int n = 1; n <= 100; ++n) mem[n][0] = 1;
  for (int c = 0; c <= 25; ++c) mem[1][c] = 1;
  for (int n = 2; n <= 100; ++n)
    for (int c = 1; c <= 2500; ++c)
      for (int k = 0; k <= 25; ++k)
        if (c - k >= 0) mem[n][c] = (mem[n][c] + mem[n - 1][c - k]) % mod;
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    scanf("%s", word);
    int c = 0, j = 0;
    for (; word[j]; ++j) c += word[j] - 'a';
    printf("%d\n", (mem[j][c] + mod - 1) % mod);
  }
  return 0;
}
