#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(vector<int> a, int n) {
  for (int i = 1; i < n; i++) {
    if (abs(a[i] - a[i - 1]) != 1) return false;
  }
  return true;
}
bool sol(vector<int> order, vector<int> cnt, int n) {
  int idx = 1, curr = order[0], next = order[1];
  vector<int> a;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (cnt[curr] == 0) {
        idx++;
        if (idx == 4) return false;
        curr = order[idx];
      }
      cnt[curr]--;
      a.push_back(curr);
    } else {
      if (cnt[next] == 0) {
        idx++;
        if (idx == 4) return false;
        next = order[idx];
      }
      cnt[next]--;
      a.push_back(next);
    }
  }
  if (check(a, n)) {
    cout << "YES\n";
    for (int i : a) {
      cout << i << " ";
    }
    cerr << "\n";
    return true;
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int n = 4;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    cin >> cnt[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  int sum = accumulate(cnt.begin(), cnt.end(), 0);
  do {
    if (sol(order, cnt, sum)) exit(0);
  } while (next_permutation(order.begin(), order.end()));
  cout << "NO\n";
  return 0;
}
