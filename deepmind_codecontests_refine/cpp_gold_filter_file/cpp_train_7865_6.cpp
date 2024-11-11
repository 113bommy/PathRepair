#include <bits/stdc++.h>
using namespace std;
set<int> a;
int p[10000000];
int main() {
  int n, x;
  cin >> n >> x;
  if (x == 2) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int A;
    cin >> A;
    if (A == 1) {
      cout << 1 << endl;
      return 0;
    }
    a.insert(A);
  }
  int res = 0;
  for (int i = 2; i <= 10000000; i++) {
    if (p[i]) continue;
    if (i >= x) break;
    if (a.find(i) == a.end()) {
      cout << -1 << endl;
      return 0;
    }
    res++;
    for (int j = i + i; j <= 10000000; j += i) p[j] = 1;
  }
  cout << res << endl;
  return 0;
}
