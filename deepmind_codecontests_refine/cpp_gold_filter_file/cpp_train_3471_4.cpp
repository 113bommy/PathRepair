#include <bits/stdc++.h>
using namespace std;
int n, k, a[100050], id[100050];
long long b, s = 0;
bool cmp(int A, int B) { return a[A] > a[B]; }
int main() {
  cin >> n >> k >> b;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    id[i] = i;
  }
  sort(id + 1, id + n, cmp);
  for (int i = 1; i <= k; i++) s += a[id[i]];
  if (b >= s) {
    printf("%d", n);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    if (s - a[id[k]] + a[i] > b) {
      printf("%d", i);
      return 0;
    }
}
