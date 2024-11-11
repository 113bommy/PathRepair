#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long n;
  cin >> n;
  vector<long long> a(n);
  map<long long, long long> cnt;
  for (auto &i : a) {
    cin >> i;
    cnt[i]++;
  }
  long long mx = -1, id;
  for (auto i : cnt)
    if (i.second > mx) mx = i.second, id = i.first;
  cout << n - mx << endl;
  long long pos = -1;
  for (long long i = 0; i < n; i++)
    if (a[i] == id) {
      pos = i;
      break;
    }
  for (long long i = pos - 1; i >= 0; i--) {
    if (a[i] < id) {
      cout << 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
    } else if (a[i] > id) {
      cout << 2 << ' ' << i + 1 << ' ' << i + 2 << '\n';
    }
  }
  for (long long i = pos + 1; i < n; i++) {
    if (a[i] < id) {
      cout << 1 << ' ' << i + 1 << ' ' << i << '\n';
    } else if (a[i] > id) {
      cout << 2 << ' ' << i + 1 << ' ' << i << '\n';
    }
  }
  return 0;
}
