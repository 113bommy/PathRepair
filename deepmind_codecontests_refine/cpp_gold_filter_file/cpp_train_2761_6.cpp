#include <bits/stdc++.h>
using namespace std;
int arr[200001];
int currPrefix[200001];
int currSuffix[200001];
int fenwickPrefix[200001];
int fenwickSuffix[200001];
int n, q;
void updatePrefix(int ind, int val) {
  if (val <= 0) return;
  while (ind <= n) {
    fenwickPrefix[ind] += val;
    ind += (ind & -ind);
  }
}
void updateSuffix(int ind, int val) {
  if (val <= 0) return;
  while (ind <= n) {
    fenwickSuffix[ind] += val;
    ind += (ind & -ind);
  }
}
int getPrefix(int ind) {
  int sum = 0;
  while (ind > 0) {
    sum += fenwickPrefix[ind];
    ind -= (ind & -ind);
  }
  return sum;
}
int getSuffix(int ind) {
  int sum = 0;
  while (ind > 0) {
    sum += fenwickSuffix[ind];
    ind -= (ind & -ind);
  }
  return sum;
}
int main() {
  int k, a, b;
  scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d %d", &x, &y);
      int tempPrefix = currPrefix[x] >= b ? 0 : min(b - currPrefix[x], y);
      int tempSuffix = currSuffix[x] >= a ? 0 : min(a - currSuffix[x], y);
      updatePrefix(x, tempPrefix);
      updateSuffix(n - x + 1, tempSuffix);
      currPrefix[x] += tempPrefix;
      currSuffix[x] += tempSuffix;
    } else {
      scanf("%d", &y);
      printf("%d\n", getPrefix(y - 1) + getSuffix(n - y - k + 1));
    }
  }
  return 0;
}
