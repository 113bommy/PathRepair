#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int minusinf = -inf;
const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};
int n, k;
char str[111111];
vector<std::pair<int, int> > as, bs;
int A, B;
int main() {
  scanf("%d%d", &n, &k);
  scanf(" %s", str);
  int j, i = 0;
  i = 0, j = 0;
  int cg = 0;
  int mxa = 0;
  while (i < n && j < n) {
    while (cg <= k && j < n) {
      if (str[j] == 'b') {
        cg++;
      }
      j++;
    }
    int d = j - i - 1;
    if (j == n && cg <= k) d++;
    mxa = max(mxa, d);
    while (i < n && (cg > k || str[i] != 'a')) {
      if (str[i] == 'b') {
        cg--;
      }
      i++;
    }
  }
  cg = 0;
  i = 0;
  j = 0;
  int mxb = 0;
  while (i < n && j < n) {
    while (cg <= k && j < n) {
      if (str[j] == 'a') {
        cg++;
      }
      j++;
    }
    int d = j - i - 1;
    if (j == n && cg <= k) d++;
    mxb = max(mxb, d);
    while (i < n && (cg > k || str[i] != 'b')) {
      if (str[i] == 'a') {
        cg--;
      }
      i++;
    }
  }
  printf("%d\n", max(mxa, mxb));
  return 0;
}
