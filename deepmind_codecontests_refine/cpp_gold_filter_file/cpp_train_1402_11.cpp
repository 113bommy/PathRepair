#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long l, r;
  cin >> l >> r;
  if (r - l <= 1) {
    cout << -1;
    return 0;
  }
  if (l % 2 == 0) {
    cout << l << " " << l + 1 << " " << l + 2;
    return 0;
  }
  if (l % 2 == 1 && r - l > 2) {
    cout << l + 1 << " " << l + 2 << " " << l + 3;
    return 0;
  } else {
    cout << -1;
    return 0;
  }
  return 0;
}
