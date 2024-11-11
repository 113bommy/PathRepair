#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, t[MAXN];
int ans = 0;
bool done[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[i + 1];
  for (int i = n; i >= 1; --i) {
    if (!done[i]) {
      ans++;
      done[i] = 1;
    }
    done[t[i]] = 1;
  }
  cout << ans << endl;
}
