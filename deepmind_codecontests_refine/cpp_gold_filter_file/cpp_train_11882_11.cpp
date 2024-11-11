#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int maxn = 1e5 + 5;
bool is_lucky(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7) return false;
    x /= 10;
  }
  return true;
}
int n, v[maxn], id[maxn], now[maxn], p[maxn];
void change(int pos1, int pos2) {
  swap(now[p[pos1]], now[p[pos2]]);
  swap(p[pos1], p[pos2]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    p[i] = id[i] = now[i] = i;
  }
  if (is_sorted(v, v + n)) return printf("0\n"), 0;
  sort(id, id + n, [](int a, int b) { return v[a] < v[b]; });
  int c = -1;
  for (int i = 0; i < n; i++)
    if (is_lucky(v[i])) {
      c = i;
      break;
    }
  if (c == -1) return printf("-1\n"), 0;
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; i++) {
    if (is_lucky(v[i])) {
      c = i;
      break;
    }
  }
  for (int i = 0; i < n; i++)
    if (p[i] != id[i]) {
      if (now[c] != i) {
        ans.emplace_back(now[c], i);
        change(now[c], i);
      }
      if (now[c] != now[id[i]]) {
        ans.emplace_back(now[c], now[id[i]]);
        change(now[c], now[id[i]]);
      }
    }
  cout << ans.size() << endl;
  for (auto x : ans) cout << x.first + 1 << " " << x.second + 1 << endl;
  return 0;
}
