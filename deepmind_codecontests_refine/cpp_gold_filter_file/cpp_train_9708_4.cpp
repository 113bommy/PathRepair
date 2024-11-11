#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e7;
vector<int> minVal(mxN + 2, 1e7 + 1);
set<int> get_primes(int num) {
  set<int> result;
  while (num > 1) {
    result.insert(minVal[num]);
    num /= minVal[num];
  }
  return result;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> is_primes(mxN + 2, 1);
  for (int i = 2; i <= mxN / 2; ++i) {
    if (!is_primes[i]) continue;
    minVal[i] = i;
    for (int j = 2; i * j <= mxN; ++j) {
      minVal[i * j] = min(minVal[i * j], i);
      is_primes[i * j] = 0;
    }
  }
  vector<pair<int, int>> result;
  for (auto x : a) {
    set<int> l = get_primes(x);
    if (l.size() < 2) {
      result.push_back(make_pair(-1, -1));
      continue;
    }
    int f = *l.begin(), s = 1;
    int cnt = 0;
    for (auto y : l) {
      if (cnt > 0) {
        s *= y;
      }
      ++cnt;
    }
    result.push_back(make_pair(f, s));
  }
  for (auto x : result) {
    cout << x.first << " ";
  }
  cout << endl;
  for (auto x : result) {
    cout << x.second << " ";
  }
  return 0;
}
