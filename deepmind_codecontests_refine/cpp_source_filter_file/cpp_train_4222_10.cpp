#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000 + 1000;
int n;
int a[MAXN], f[MAXN];
int d[MAXN], l;
int key;
void input() {
  scanf("%d", &n);
  for (int i = 1, k; i <= n; i++) {
    scanf("%d", &k);
    a[k] = i;
  }
  for (int i = 1, k; i <= n; i++) {
    scanf("%d", &k);
    f[a[k]] = n - i + 1;
  }
}
int biner_search(int s, int f) {
  if (f - s == 1) return f;
  if (d[(f + s) / 2] < key) return biner_search((f + s) / 2, f);
  return biner_search(s, (f + s) / 2);
}
void Longest_increasing_subsequence() {
  for (int i = 1; i <= n; i++) {
    key = f[i];
    if (key > d[l]) {
      d[l + 1] = key;
      l++;
    } else {
      int k = biner_search(0, l);
      d[k] = key;
    }
  }
}
int main() {
  input();
  Longest_increasing_subsequence();
  printf("%d", &l);
  return 0;
}
