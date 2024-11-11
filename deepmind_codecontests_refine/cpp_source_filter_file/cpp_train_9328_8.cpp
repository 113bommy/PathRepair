#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
long long n, a[N], b[N], vis[N];
set<long long> s[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int MyPos = lower_bound(b, b + n, a[i]) - b;
      s[j].insert(i);
      while (s[j].find(MyPos) == s[j].end()) {
        s[j].insert(MyPos);
        vis[MyPos] = 1;
        long long r = a[MyPos];
        MyPos = lower_bound(b, b + n, r) - b;
      }
      j++;
    }
  }
  cout << j << endl;
  for (int i = 0; i < j; i++) {
    cout << s[i].size() << " ";
    for (auto x : s[i]) {
      cout << a[x] << " ";
    }
    cout << endl;
  }
  return 0;
}
