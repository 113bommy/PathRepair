#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  scanf("%d", &n);
  scanf("%d", &q);
  int maxi = -1;
  deque<int> dq;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    maxi = max(maxi, x);
    dq.push_back(x);
  }
  vector<pair<int, int> > operation;
  while (dq.front() != maxi) {
    int a = dq.front();
    dq.pop_front();
    int b = dq.front();
    dq.pop_front();
    operation.push_back(pair<int, int>(a, b));
    if (a >= b) {
      dq.push_front(a);
      dq.push_back(b);
    } else {
      dq.push_front(b);
      dq.push_back(a);
    }
  }
  dq.pop_front();
  vector<int> nos;
  while (!dq.empty()) {
    nos.push_back(dq.front());
    dq.pop_front();
  }
  for (int i = 0; i < q; i++) {
    long long int qu;
    scanf("%lld", &qu);
    qu--;
    if (qu < operation.size()) {
      printf("%d %d\n", operation[qu].first, operation[qu].second);
    } else {
      qu -= operation.size();
      qu %= (n - 1);
      printf("%d %d", maxi, nos[qu]);
    }
  }
  return 0;
}
