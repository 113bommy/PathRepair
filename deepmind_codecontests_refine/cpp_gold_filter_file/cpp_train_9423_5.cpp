#include <bits/stdc++.h>
using namespace std;
int daysB[200001];
int daysA[200001];
int fenWick1[200001];
int fenWick2[200001];
int n, k, a, b, q, type;
int di, ai;
int pi;
void update1(int index, int val) {
  while (index <= n) {
    fenWick1[index] += val;
    index += index & (-index);
  }
}
void update2(int index, int val) {
  while (index <= n) {
    fenWick2[index] += val;
    index += index & (-index);
  }
}
int query(int *arr, int index) {
  int sum = 0;
  while (index) {
    sum += arr[index];
    index = index ^ (index & (-index));
  }
  return sum;
}
int main() {
  scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
  while (q--) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d%d", &di, &ai);
      if (daysB[di] + ai > b) {
        int pl = b - daysB[di];
        daysB[di] += pl;
        update1(di, pl);
      } else {
        daysB[di] += ai;
        update1(di, ai);
      }
      if (daysA[di] + ai > a) {
        int pl = a - daysA[di];
        daysA[di] += pl;
        update2(di, pl);
      } else {
        daysA[di] += ai;
        update2(di, ai);
      }
    } else {
      scanf("%d", &pi);
      int res = query(fenWick1, pi - 1) +
                (query(fenWick2, n) - query(fenWick2, pi + k - 1));
      printf("%d\n", res);
    }
  }
}
