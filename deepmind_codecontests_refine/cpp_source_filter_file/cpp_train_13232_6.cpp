#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, l;
  cin >> n >> m >> l;
  vector<long long> vec(n);
  set<long long> s;
  for (long long i = 0; i < n; ++i) {
    cin >> vec[i];
    if (vec[i] > l) s.insert(i);
  }
  long long cnt = 0;
  long long prev = -2;
  for (auto x : s) {
    if (x > prev + 1) ++cnt;
    prev = x;
  }
  while (m > 0) {
    --m;
    int q;
    cin >> q;
    if (q == 0) {
      cout << cnt << endl;
    } else {
      long long p, d;
      cin >> p >> d;
      --p;
      vec[p] += d;
      if (vec[p] > l) s.insert(p);
      if (vec[p] > l && vec[p] - d <= l) {
        if (p > 0 && p == n - 1) {
          if (vec[p - 1] < l) ++cnt;
        } else if (p < n - 1 && p == 0) {
          if (vec[p + 1] < l) ++cnt;
        } else if (p < n - 1 && p > 0) {
          if (vec[p + 1] <= l && vec[p - 1] <= l)
            ++cnt;
          else if (vec[p + 1] > l && vec[p - 1] > l)
            --cnt;
        } else if (p == 0 && p == n - 1) {
          if (vec[p] > l && vec[p] - d <= l) ++cnt;
        }
      }
    }
  }
  return 0;
}
