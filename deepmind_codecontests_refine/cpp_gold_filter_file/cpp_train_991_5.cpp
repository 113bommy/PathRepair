#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
const int INF = 1e9 + 7;
int n;
int t[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  t[0] = 0;
  t[n + 1] = t[n];
  for (int i = 0; i <= n; ++i)
    if (t[i] + 15 < t[i + 1]) return cout << t[i] + 15, 0;
  cout << min(t[n] + 15, 90);
}
