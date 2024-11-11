#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e15;
const int N = 2020;
int n, k;
long long a[N], b[N];
int bal[N];
long long sum;
bool usedA[N], usedB[N];
void makeIter() {
  long long bst = INF;
  int bstA = -1, bstB = -1;
  int curB = -1;
  int r = n;
  for (int i = n - 1; i >= 0; i--) {
    while (r > 0 && (r > i || bal[r - 1] > 0)) {
      r--;
      if (!usedB[r]) {
        if (curB == -1 || b[r] < b[curB]) {
          curB = r;
        }
      }
    }
    if (!usedA[i] && curB != -1 && a[i] + b[curB] < bst) {
      bst = a[i] + b[curB];
      bstA = i;
      bstB = curB;
    }
  }
  sum += bst;
  for (int i = bstA; i < n; i++) bal[i]++;
  for (int i = bstB; i < n; i++) bal[i]--;
  usedA[bstA] = usedB[bstB] = 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
  while (k--) makeIter();
  printf("%lld\n", sum);
  return 0;
}
