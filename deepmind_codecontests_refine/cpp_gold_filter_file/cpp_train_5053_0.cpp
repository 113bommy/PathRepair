#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> v{};
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  long long lo = 0;
  long long hi = 2 * 1000 * 1000 * 1001;
  while (lo + 1 != hi) {
    long long mid = (lo + hi) / 2;
    long long s = 0;
    for (int i = 0; i < n; ++i) s += max(0ll, mid - v[i]);
    if (s > k)
      hi = mid;
    else
      lo = mid;
  }
  int dk = k;
  for (int i = 0; i < n; ++i) {
    if (lo > v[i]) {
      dk -= lo - v[i];
      v[i] = lo;
    }
  }
  for (int i = 0; i < n && dk; ++i) {
    if (v[i] == lo) {
      ++v[i];
      --dk;
    }
  }
  lo = 0;
  hi = 2 * 1000 * 1000 * 1001;
  while (lo + 1 != hi) {
    long long mid = (lo + hi) / 2;
    long long s = 0;
    for (int i = 0; i < n; ++i) s += max(0ll, v[i] - mid);
    if (s < k)
      hi = mid;
    else
      lo = mid;
  }
  int ik = k;
  for (int i = 0; i < n; ++i) {
    if (lo < v[i]) {
      ik -= v[i] - lo;
      v[i] = lo;
    }
  }
  for (int i = 0; i < n && ik < 0; ++i) {
    if (v[i] == lo) {
      ++v[i];
      ++ik;
    }
  }
  cout << (*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()))
       << endl;
  return 0;
}
