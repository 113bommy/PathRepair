#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long ans[N];
int main() {
  int n;
  cin >> n;
  map<long long, int> events;
  for (int i = 0; i < n; ++i) {
    long long l, r;
    cin >> l >> r;
    ++events[l];
    --events[r + 1];
  }
  int cur = 0, pos = 0;
  for (auto &i : events) {
    ans[cur] += i.first - pos;
    pos = i.first;
    cur += i.second;
  }
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << ' ';
  }
}
