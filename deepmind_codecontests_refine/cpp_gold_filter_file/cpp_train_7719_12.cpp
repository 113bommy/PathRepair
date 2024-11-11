#include <bits/stdc++.h>
using namespace std;
template <typename T>
using pii = pair<T, T>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m, cnt = 0;
  cin >> n >> m;
  if (m == 0)
    cout << 1;
  else {
    cout << min(n - m, m);
  }
  return 0;
}
