#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 20;
long long aabs(long long x) { return x < 0 ? -x : x; }
struct node {
  long long num;
  int id;
  bool operator<(const node &temp) const { return aabs(num) > aabs(temp.num); }
};
long long n, k, x, a[N];
int main() {
  cin >> n >> k >> x;
  int sign = 1;
  priority_queue<node> Q;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
    if (a[i] < 0) sign = -sign;
    Q.push((node){a[i], i});
  }
  while (k--) {
    node temp = Q.top();
    Q.pop();
    if (a[temp.id] < 0) {
      if (sign == -1)
        a[temp.id] -= x;
      else
        a[temp.id] += x;
      if (a[temp.id] >= 0) sign = -sign;
    } else {
      if (sign == -1)
        a[temp.id] += x;
      else
        a[temp.id] -= x;
      if (a[temp.id] < 0) sign = -sign;
    }
    Q.push((node){a[temp.id], temp.id});
  }
  for (int i = 1; i <= n; i++) printf("%lld%c", a[i], i == n ? '\n' : ' ');
  return 0;
}
