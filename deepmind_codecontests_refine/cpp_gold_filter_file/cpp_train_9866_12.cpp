#include <bits/stdc++.h>
using namespace std;
struct node {
  long long p, c;
  int index;
  bool operator<(const node nod) const { return p < nod.p; }
} no[100005];
struct va {
  long long v;
  va() {}
  va(long long v) : v(v) {}
  bool operator<(const va nod) const { return v > nod.v; }
  bool operator>(const va nod) const { return v < nod.v; }
} val[100005];
long long n, k, sum;
long long ans[100005];
priority_queue<va> pq;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> no[i].p, no[i].index = i + 1;
  for (int i = 0; i < n; i++) cin >> no[i].c, ans[i + 1] = no[i].c;
  sort(no, no + n);
  for (int i = 0; i < n; i++) {
    if (i > 0) pq.push(va(no[i - 1].c)), sum += no[i - 1].c;
    ;
    if (i > k) {
      sum -= pq.top().v;
      pq.pop();
    }
    ans[no[i].index] += sum;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
