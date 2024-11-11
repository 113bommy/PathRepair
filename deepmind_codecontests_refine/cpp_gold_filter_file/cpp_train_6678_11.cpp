#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long int n;
  cin >> n;
  long long int ar[n];
  unordered_map<long long int, long long int> fr;
  for (long long int i = 0; i < n; i++) cin >> ar[i], fr[ar[i]]++;
  long long int oprt = 0;
  long long int mx = 0;
  long long int elmt = 0;
  for (auto a : fr) {
    if (mx < a.second) {
      mx = a.second;
      elmt = a.first;
    }
  }
  vector<pair<long long int, pair<long long int, long long int>>> v;
  long long int indx = 0;
  for (long long int i = 0; i < n; i++)
    if (ar[i] == elmt) {
      indx = i;
      break;
    }
  for (long long int i = indx; i > 0; i--) {
    if (ar[i - 1] < ar[i]) {
      oprt++;
      ar[i - 1] += abs(ar[i - 1] - ar[i]);
      v.push_back({1, {i, i + 1}});
    } else if (ar[i - 1] > ar[i]) {
      oprt++;
      ar[i - 1] -= abs(ar[i - 1] - ar[i]);
      v.push_back({2, {i, i + 1}});
    }
  }
  for (long long int i = indx; i < n - 1; i++) {
    if (ar[i + 1] < ar[i]) {
      oprt++;
      ar[i + 1] += abs(ar[i + 1] - ar[i]);
      v.push_back({1, {i + 2, i + 1}});
    } else if (ar[i + 1] > ar[i]) {
      oprt++;
      ar[i + 1] -= abs(ar[i + 1] - ar[i]);
      v.push_back({2, {i + 2, i + 1}});
    }
  }
  cout << oprt << endl;
  for (auto a : v) {
    cout << a.first << " " << a.second.first << " " << a.second.second << endl;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
