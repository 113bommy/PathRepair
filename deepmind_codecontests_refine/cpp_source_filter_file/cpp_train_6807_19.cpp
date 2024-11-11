#include <bits/stdc++.h>
using namespace std;
int mod = (int)1e9 + 7;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
void solve() {
  int n;
  cin >> n;
  if (n <= 2) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << i << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << (i + 1) % n << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << (i + i + 1) % n << " ";
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
