#include <bits/stdc++.h>
const int MAX = 11111;
using namespace std;
vector<string> A;
static int get(char x) {
  static char T[] = "RGBYW12345";
  for (int i = 0; i < (9); ++i) {
    if (x == T[i]) {
      return i;
    }
  }
  return -1;
}
static void bip(int x) {
  for (int i = (10); i >= 0; --i) {
    if ((1 << i) & x) {
      printf("1");
    } else {
      printf("0");
    }
  }
  printf("\n");
}
int main() {
  set<string> tmp;
  int(N);
  scanf("%d", &N);
  for (int i = 0; i < (N); ++i) {
    string x;
    cin >> x;
    A.push_back(x);
    tmp.insert(x);
  }
  if ((int((tmp).size())) == 1) {
    printf("0");
    return 0;
  }
  int res = 100, M = 1 << 10;
  for (int msk = (1); msk < (M); ++msk) {
    int cnt = 0;
    for (int j = 0; j < ((int((A).size()))); ++j) {
      int can = 1;
      for (int k = 0; k < ((int((A).size()))); ++k) {
        if (A[j] == A[k]) continue;
        int x1 = (1 << get(A[j][0])) & msk;
        int x2 = (1 << get(A[j][1])) & msk;
        int y1 = (1 << get(A[k][0])) & msk;
        int y2 = (1 << get(A[k][1])) & msk;
        int z1 = x1 | x2;
        int z2 = y1 | y2;
        if (z1 ^ z2) continue;
        if (x1 != y1) continue;
        if (x2 != y2) continue;
        if (x1 && x2 && y1 && y2) continue;
        can = 0;
        break;
      }
      cnt += can;
    }
    if (cnt == N) {
      res = min(res, ((int)__builtin_popcount(msk)));
    }
  }
  printf("%d", res);
  return 0;
}
