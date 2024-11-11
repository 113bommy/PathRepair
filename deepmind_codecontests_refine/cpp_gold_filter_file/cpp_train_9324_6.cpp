#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int arr[MAX];
int bit1[MAX];
long long bit2[MAX];
void upd1(int x) {
  while (x) {
    bit1[x] += 1;
    x -= (x & (-x));
  }
}
void upd2(int x, long long val) {
  while (x) {
    bit2[x] += val;
    x -= (x & (-x));
  }
}
long long query2(int x) {
  long long ans = 0;
  while (x < MAX) {
    ans += bit2[x];
    x += (x & (-x));
  }
  return ans;
}
int query1(int x) {
  int ans = 0;
  while (x < MAX) {
    ans += bit1[x];
    x += (x & (-x));
  }
  return ans;
}
int main() {
  long long n;
  scanf("%lld", &n);
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    long long right = (n - i + 1);
    ans += ((i - 1) * 1ll * (i)*right) / (double)(n * (n + 1) * 2);
    long long cnt = query1(a);
    long long val = query2(a);
    ans += (cnt - (((right * val / (double)(n)) * 2) / (double)(n + 1)));
    upd1(a);
    upd2(a, i);
  }
  printf("%0.9lf\n", ans);
}
