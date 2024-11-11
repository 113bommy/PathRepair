#include <bits/stdc++.h>
int dx[] = {0, 0, 1, 1};
int dy[] = {1, 1, 0, 0};
using namespace std;
vector<int> v, v2, v3;
vector<int>::iterator it1, it2;
int main() {
  int tcase = 1;
  while (tcase--) {
    int n, m, a, b, w1, h1, w2, h2, ans = 0, cnt = 0, ck = 0, cka = 0, ckb = 0,
                                    mx = 0, dr = 0, pos, ma = -1, cnt1 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a);
      if (a > 0) cnt++;
      if (a < 0) cnt1++;
    }
    int x = n / 2 + (n % 2 != 0);
    if (cnt >= x) {
      printf("1\n");
    } else if (cnt1 >= x) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  }
}
