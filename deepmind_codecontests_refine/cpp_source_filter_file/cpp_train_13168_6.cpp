#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int inf = 0x7ffffff;
const int maxn = 1000 + 5, maxp = 1e5 + 5;
int B_ind[maxp], S_ind[maxp];
struct buy {
  int p, q;
} B[maxn];
struct sell {
  int p, q, ind;
} S[maxn];
bool cmpb(const buy &a, const buy &b) { return a.p > b.p; }
bool cmps(const sell &a, const sell &b) { return a.p < b.p; }
bool ccc(const sell &a, const sell &b) { return a.ind < b.ind; }
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  int i = 1, j = 1;
  char c[3];
  int price, vol;
  for (int k = 0; k < n; k++) {
    scanf("%s %d %d", c, &price, &vol);
    if (c[0] == 'B') {
      if (B_ind[price] == 0) {
        B_ind[price] = i;
        B[i] = {price, vol};
        i++;
      } else {
        B[B_ind[price]].q += vol;
      }
    } else {
      if (S_ind[price] == 0) {
        S_ind[price] = j;
        S[j] = {price, vol, j};
        j++;
      } else {
        S[S_ind[price]].q += vol;
      }
    }
  }
  sort(B + 1, B + i, cmpb);
  sort(S + 1, S + j, cmps);
  int temp = min(s + 1, j);
  sort(S + 1, S + temp, ccc);
  for (int k = 1; k < temp; k++) printf("S %d %d\n", S[k].p, S[k].q);
  for (int k = 1; k <= s && k < i; k++) printf("B %d %d\n", B[k].p, B[k].q);
  return 0;
}
