#include <bits/stdc++.h>
using namespace std;
int cnt[5000001];
int sum[5000001];
bool mark[5000001];
int get(int n, int x) {
  int cnt = 0;
  while (n % x == 0) n /= x, cnt++;
  return cnt;
}
void sieve() {
  cnt[1] = 1;
  int i, r, root = sqrt(5000001);
  for (i = 2; i < 5000001; i++) {
    if (mark[i]) continue;
    cnt[i]++;
    for (r = i + i; r <= 5000001; r += i) mark[r] = true, cnt[r] += get(r, i);
  }
  for (i = 1; i <= 5000001; i++) sum[i] = sum[i - 1] + cnt[i];
}
int main() {
  sieve();
  int n;
  scanf("%d", &n);
  while (n--) {
    int a, b;
    scanf("%d %d", &a, &b);
    cout << sum[a] - sum[b] << '\n';
  }
  return 0;
}
