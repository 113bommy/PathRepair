#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, maxn = 0, a;
  set<long long> s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    while (s.count(a)) {
      s.erase(a);
      a++;
    }
    s.insert(a);
    maxn = max(a, maxn);
  }
  cout << maxn + 1 - s.size() << endl;
}
