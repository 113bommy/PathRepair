#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
long long s[N + 1];
long long getn(int i) {
  long long ans = 0;
  int c = 999999;
  int x = 7;
  while (i > 0) {
    if (i > c) {
      ans += x * (i - c);
      i = c;
    }
    c /= 10;
    x--;
  }
  return ans;
}
int bestFit(long long k) {
  int l = 0, r = N;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (s[m] < k) {
      l = m;
    } else
      r = m - 1;
  }
  return l;
}
char getAns(long long k) {
  int c = 9;
  int x = 1;
  while (k > x * c) {
    k = k - x * c;
    x++;
    c *= 10;
  }
  int num = (c / 9 - 1) + ceil(1.0L * k / x);
  int pos = ((k - 1) % x);
  return std::to_string(num)[pos];
}
void solve() {
  long long k;
  scanf("%lld", &k);
  int j = bestFit(k);
  k -= s[j];
  printf("%c\n", getAns(k));
}
int main() {
  s[0] = 0;
  s[1] = 1;
  for (int i = 2; i <= N; i++) {
    s[i] = s[i - 1] + getn(i);
  }
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    solve();
  }
  getchar();
  getchar();
}
