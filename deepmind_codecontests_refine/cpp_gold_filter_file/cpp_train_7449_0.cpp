#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  long long x;
  cin >> n >> k >> x;
  vector<long long> a(n);
  vector<int> q(n);
  int nneg = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    q[i] = i;
    if (a[i] < 0) nneg++;
  }
  auto cmp = [&](int i, int j) { return llabs(a[i]) > llabs(a[j]); };
  make_heap(q.begin(), q.end(), cmp);
  while (k) {
    int i = q.front();
    pop_heap(q.begin(), q.end(), cmp);
    if (nneg % 2) {
      if (a[i] < 0) {
        a[i] -= x;
      } else {
        a[i] += x;
      }
    } else {
      if (a[i] < 0) {
        a[i] += x;
        if (a[i] >= 0) nneg--;
      } else {
        a[i] -= x;
        if (a[i] < 0) nneg++;
      }
    }
    k--;
    push_heap(q.begin(), q.end(), cmp);
  }
  cout << a[0];
  for (int i = 1; i < n; i++) cout << ' ' << a[i];
  cout << '\n';
}
