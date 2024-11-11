#include <bits/stdc++.h>
using namespace std;
int a[900000], N, k, p;
set<long long> s;
int main() {
  cin >> N >> k;
  for (int i = 0; i < N; i++) cin >> a[i];
  sort(a, a + N);
  for (int i = 0; i < N; i++) {
    p = s.size();
    if (!(a[i] % k)) {
      s.insert(a[i] / k);
      if (p != s.size()) s.erase(a[i] / k), s.insert(a[i]);
    } else
      s.insert(a[i]);
  }
  cout << s.size() << endl;
  return 0;
}
