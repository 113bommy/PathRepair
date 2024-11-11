#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void trace(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void trace(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
int n, h, m, k;
int main() {
  cin >> n >> h >> m >> k;
  m /= 2;
  vector<pair<int, int>> arr(n, {0, 0});
  deque<int> q;
  for (int i = 0; i < n; i++) {
    int hh, mm;
    cin >> hh >> mm;
    mm %= m;
    arr[i].first = mm;
    arr[i].second = i;
  }
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) arr.push_back(arr[i]), arr.back().first += m;
  int r = 1, mx = INT_MAX, start = 0, ans = 0, l = 0, sz = 0;
  for (int i = 0; i < n; i++) {
    int num = arr[i].first;
    if (q.size() && q.front() == num) q.pop_front();
    r = max(r, i + 1);
    while (arr[r].first <= num + k - 1) q.push_back(arr[r++].first);
    if (q.size() < mx) {
      mx = q.size();
      start = (num + k) % m;
      if (q.size()) l = i + 1;
    }
  }
  cout << mx << " " << start << endl;
  if (mx)
    for (int i = l; i < l + mx; i++) cout << arr[i].second + 1 << endl;
}
