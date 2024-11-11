#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, H = 85069, P = 1e9 + 7;
unordered_map<int, vector<int>> v;
priority_queue<pair<int, int>> s;
int a[N], h[N], p[N] = {1};
int Hash(int st, int en) {
  return (h[en] - (~st ? 1LL * h[st] * p[en - st] % P : 0) + P) % P;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; v[a[i]].push_back(i), i++) {
    cin >> a[i], p[i + 1] = 1LL * p[i] * H % P,
                       h[i] = (1LL * h[i - 1] * H + a[i]) % P;
    for (auto j : v[a[i]])
      if (j + 1 >= i - j && Hash(j, i) == Hash(j + j - i, j))
        s.push({j - i, i - j - j - 1});
  }
  int st = 0;
  while (!s.empty())
    st = -(s.top().second <= -st ? s.top().first + s.top().second : -st),
    s.pop();
  cout << n - st << endl;
  while (st < n) cout << a[st++] << ' ';
  return 0;
}
