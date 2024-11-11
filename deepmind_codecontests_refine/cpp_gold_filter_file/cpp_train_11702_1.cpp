#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
vector<long long> v(100004);
vector<long long> t(100004, 0);
int n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int bsearch(int r, int key) {
  int l = -1;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (t[m] >= key) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}
int longest() {
  int length = 1;
  t[0] = v[0];
  for (int i = 1; i < n; ++i) {
    if (v[i] < t[0])
      t[0] = v[i];
    else if (v[i] > t[length - 1]) {
      t[length] = v[i];
      length++;
    } else {
      t[bsearch(length - 1, v[i])] = v[i];
    }
  }
  return length;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cout << longest();
  return 0;
}
