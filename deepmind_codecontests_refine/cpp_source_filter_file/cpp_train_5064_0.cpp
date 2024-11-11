#include <bits/stdc++.h>
using namespace std;
using Int = long long;
constexpr static int mod = 1e9 + 7;
constexpr static int inf = (1 << 30) - 1;
constexpr static Int infll = (1LL << 61) - 1;
int Competitive_Programming =
    (ios_base::sync_with_stdio(false), cin.tie(nullptr),
     cout << fixed << setprecision(15), 0);
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
  int N;
  cin >> N;
  vector<pair<pair<int, int>, int>> v;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    int sc = count(s[i].begin(), s[i].end(), 's'),
        hc = count(s[i].begin(), s[i].end(), 'h');
    v.emplace_back(make_pair(sc, hc), i);
  }
  sort(v.begin(), v.end(),
       [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
         return a.first.first * b.first.second > a.first.second * b.first.first;
       });
  Int ans = 0, sum = 0;
  for (int i = 0; i < N; i++) {
    int ind = v[i].second;
    string t = s[ind];
    for (int j = 0; j < t.size(); j++) {
      if (t[j] == 's')
        sum++;
      else
        ans += sum;
    }
  }
  cout << ans << "\n";
}
