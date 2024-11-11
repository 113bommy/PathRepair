#include <bits/stdc++.h>
using namespace std;
constexpr int MM = 998244353;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long n, k;
  cin >> n >> k;
  vector<long long> a;
  set<long long> s;
  long long p = 0;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (s.count(x)) {
      continue;
    }
    if (s.size() < k) {
      a.push_back(x);
      s.insert(x);
    } else {
      s.erase(a[a.size() - k]);
      a.push_back(x);
      s.insert(x);
    }
  }
  cout << min(k, (long long)s.size());
  for (long long i = a.size() - 1, j = 0;
       i >= 0 && j < min(k, (long long)s.size()); i--, j++) {
    cout << a[i] << " ";
  }
  return 0;
}
