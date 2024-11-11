#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long l, r, i = 0, p = 0;
  cin >> l >> r;
  while (l | r) {
    ++i;
    if (l & 1 ^ r & 1) p = i;
    l >>= 1;
    r >>= 1;
  }
  cout << (1ll << p) - 1;
  return 0;
}
