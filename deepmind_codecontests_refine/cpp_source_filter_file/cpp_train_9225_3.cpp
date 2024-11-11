#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
vector<pair<int, int> > ini, fim;
long long ans;
int n, m, k;
void f(int i, int j) {
  if (i > j) return;
  if (i == j) {
    ans += (((long long)m * v[i].second) / (long long)k) * (long long)k;
    if ((m * v[i].second) % k != 0) ini.clear(), fim.clear();
    return;
  }
  if (v[i].first == v[j].first && (v[i].second + v[j].second) % k == 0) {
    ans += ((long long)(v[i].second + v[j].second) * (long long)(m - 1));
    ini.push_back(v[i]);
    fim.push_back(v[j]);
    f(i + 1, j - 1);
    return;
  } else if (v[i].first == v[j].first) {
    ans += (((long long)(v[i].second + v[j].second) / (long long)k) *
            (long long)k) *
           (long long)(m - 1);
    ini.clear();
    fim.clear();
    return;
  } else {
    ini.clear();
    fim.clear();
    return;
  }
}
int main() {
  ios::sync_with_stdio(false);
  ans = 0LL;
  cin >> n >> k >> m;
  int ai;
  for (int i = 0; i < n; i++) {
    cin >> ai;
    if (!v.size() || v.back().first != ai)
      v.push_back({ai, 1});
    else {
      v.back().second++;
      if (v.back().second == k) ans += k, v.pop_back();
    }
  }
  ans *= (long long)m;
  if (m == 1) {
    cout << ((long long)n - ans) << "\n";
    return 0;
  }
  f(0, v.size() - 1);
  while (ini.size() && fim.size()) {
    if (ini.back().first == fim.back().first) {
      ans +=
          ((long long)(ini.back().second + fim.back().second) / (long long)k) *
          (long long)k;
      if ((ini.back().second + fim.back().second) % k != 0) break;
      ini.pop_back();
      fim.pop_back();
    } else
      break;
  }
  cout << ((long long)n * m - ans) << "\n";
  return 0;
}
