#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  long long k;
  long long c;
} NODE;
bool cmp(NODE a, NODE b) { return a.c < b.c; }
int main() {
  long long n, t, b[105], sum = 0, money = 0, cnt = 0;
  int i, j;
  NODE a[105];
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i].k >> a[i].c;
  cin >> t;
  for (i = 1; i <= t; i++) cin >> b[i];
  b[0] = 0;
  sort(a, a + n, cmp);
  for (i = 0, j = 1; i < n; i++) {
    if (a[i].k + sum <= b[j]) {
      money += a[i].k * a[i].c * j;
      sum += a[i].k;
    } else {
      while (j <= t && a[i].k + sum - cnt > b[j]) {
        long long k = (b[j] - sum);
        money += k * j * a[i].c;
        sum += k;
        cnt += k;
        j++;
      }
      money += a[i].c * (a[i].k - cnt) * j;
      sum += a[i].k - cnt;
      cnt = 0;
    }
  }
  cout << money << endl;
}
