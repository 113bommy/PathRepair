#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  unordered_set<long long> A;
  deque<int> ret;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    long long xx = (long long)x * x;
    if (A.find(xx) == A.end()) {
      ret.push_back(x);
      A.insert(xx);
      if (ret.size() > m) {
        int y = ret.front();
        ret.pop_front();
        A.erase((long long)y * y);
      }
    }
  }
  printf("%d\n", (int)ret.size());
  reverse(ret.begin(), ret.end());
  for (int i = 0; i < ret.size(); ++i) {
    printf("%d%c", ret[i], " \n"[i + 1 == ret.size()]);
  }
  return 0;
}
