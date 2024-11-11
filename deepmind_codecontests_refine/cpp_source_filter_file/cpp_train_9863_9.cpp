#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  long long p[n], c[n], pc[n];
  map<long long, long long> m;
  set<int> s;
  for (long long i = 0; i < n; i++) {
    cin >> p[i];
    pc[i] = p[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> c[i];
    m[p[i]] = c[i];
  }
  sort(pc, pc + n);
  if (k == 0 || n == 1) {
    for (long long i = 0; i < n; i++) cout << c[i] << " ";
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    if (i == 0) {
      s.insert(m[pc[i]]);
    } else {
      int f = 0;
      set<int>::iterator it;
      it = --s.end();
      long long temp = m[pc[i]];
      while (f < k) {
        m[pc[i]] += (*it);
        f++;
        if (it == s.begin()) break;
        it--;
      }
      s.insert(temp);
    }
  }
  for (long long i = 0; i < n; i++) cout << m[p[i]] << " ";
}
