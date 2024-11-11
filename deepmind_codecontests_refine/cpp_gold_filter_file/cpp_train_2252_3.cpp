#include <bits/stdc++.h>
using namespace std;
long long a[200005], b[200005];
vector<long long> sq, nsq, v;
void square() {
  for (long long i = 0; i <= 100000; i++) a[i] = i * i;
  return;
}
int main() {
  square();
  long long n;
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
  for (int i = 0; i < n; i++) {
    long long s = sqrt(b[i]);
    long long t = s * s;
    if (t == b[i])
      sq.push_back(b[i]);
    else
      nsq.push_back(b[i]);
  }
  long long ans = 0;
  if ((int)sq.size() < n / 2) {
    for (int i = 0; i < (int)nsq.size(); i++) {
      int low = lower_bound(a, a + 100001, nsq[i]) - a;
      int up = upper_bound(a, a + 100001, nsq[i]) - a;
      low--;
      v.push_back(min(a[up] - nsq[i], nsq[i] - a[low]));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < (n / 2) - (int)sq.size(); i++) ans += v[i];
  } else if ((int)sq.size() > n / 2) {
    sort(sq.begin(), sq.end());
    for (int i = (int)sq.size() - 1; i >= (n / 2); i--) {
      if (sq[i] == 0)
        ans += 2;
      else
        ans++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
