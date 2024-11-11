#include <bits/stdc++.h>
using namespace std;
int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  long long n, x, y, k;
  cin >> n >> k >> x;
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    cin >> y;
    v.push_back(y);
  }
  if (k > 92) {
    long long times = min(k, 92LL);
    k = k % 92;
    for (int i = 0; i < times + k; i++) {
      sort(v.begin(), v.end());
      for (int h = 0; h < v.size(); h++) {
        if (h % 2 == 0) v[h] ^= x;
      }
    }
  } else {
    for (int i = 0; i < k; i++) {
      sort(v.begin(), v.end());
      for (int h = 0; h < v.size(); h++) {
        if (h % 2 == 0) v[h] ^= x;
      }
    }
  }
  sort(v.begin(), v.end());
  cout << v.back() << " " << v.front() << endl;
  return 0;
}
