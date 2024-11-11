#include <bits/stdc++.h>
using namespace std;
int myabs(int x) { return (x > 0 ? x : -x); }
int a[1111111], res[1111111];
int main() {
  int n;
  cin >> n;
  if (n % 2 == 1) {
    cout << "NO" << endl;
    return 0;
  }
  multiset<int> q;
  int max = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x > max) max = x;
    q.insert(x);
  }
  q.erase(q.find(max));
  res[0] = max;
  res[1] = max - 1;
  res[n - 1] = max - 1;
  if (q.find(max - 1) == q.end()) {
    cout << "NO" << endl;
    return 0;
  }
  q.erase(q.find(max - 1));
  if (q.find(max - 1) == q.end()) {
    cout << "NO" << endl;
    return 0;
  }
  q.erase(q.find(max - 1));
  for (int i = 2; i < n - 1; ++i) {
    if (q.find(res[i - 1] + 1) != q.end()) {
      res[i] = res[i - 1] + 1;
      q.erase(q.find(res[i - 1] + 1));
      continue;
    }
    if (q.find(res[i - 1] - 1) != q.end()) {
      res[i] = res[i - 1] - 1;
      q.erase(q.find(res[i - 1] - 1));
      continue;
    }
    cout << "NO" << endl;
    return 0;
  }
  if (myabs(res[n - 1] - res[n - 2]) == 1) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
