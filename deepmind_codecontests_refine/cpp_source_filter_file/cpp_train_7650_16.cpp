#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n;
bool used[N];
set<int> setik;
inline bool f(int x) {
  if (x < 2) return false;
  for (int j = 2; j * j <= x; ++j)
    if (x % j == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  if (n == 1) return cout << 0, 0;
  for (int i = 2; i < n; ++i) {
    if (f(i))
      for (int j = i; j <= n; j *= i) setik.insert(j);
  }
  cout << setik.size() << '\n';
  for (auto it : setik) cout << it << ' ';
}
