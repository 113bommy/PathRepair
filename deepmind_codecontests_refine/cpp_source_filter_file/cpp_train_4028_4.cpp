#include <bits/stdc++.h>
using namespace std;
template <typename T>
void dbg(T t) {
  cerr << t << endl;
}
template <typename T, typename... Args>
void dbg(T t, Args... args) {
  cerr << t << " ";
  dbg(args...);
}
void dfs(int rt) {}
int cnt[100000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, h = 0, a, b, mx;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
  }
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 1)
      v.push_back(i);
    else if (cnt[i] > 2)
      h++, mx = i;
  }
  if (h > 1) {
    return cout << "NO\n", 0;
  }
  cout << "YES\n";
  if (h == 0) {
    cout << 1 << endl;
    cout << v.front() + 1 << ' ' << v.back() + 1 << endl;
  } else {
    cout << v.size() << endl;
    for (int k : v) {
      cout << mx + 1 << ' ' << k + 1 << '\n';
    }
  }
  return 0;
}
