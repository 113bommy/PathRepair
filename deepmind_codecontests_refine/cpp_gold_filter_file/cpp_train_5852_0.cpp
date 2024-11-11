#include <bits/stdc++.h>
using namespace std;
vector<int> A, B;
long long C[100000];
vector<tuple<int, int, long long>> ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ((void)0);
  ((void)0);
  ((void)0);
  int N, M;
  for (cin >> N >> M; M--;) {
    int a, b, c;
    cin >> a >> b >> c;
    C[--a] += c;
    C[--b] -= c;
  }
  for (int i = 0; i < N; i++) {
    if (C[i] > 0)
      A.push_back(i);
    else if (C[i] < 0)
      B.push_back(i);
  }
  for (auto a : A) {
    while (C[a] && B.size()) {
      long long m = min(C[a], -C[B.back()]);
      C[a] -= m;
      ans.emplace_back(a + 1, B.back() + 1, m);
      if ((C[B.back()] += m) == 0) B.pop_back();
    }
  }
  cout << ans.size() << '\n';
  for (auto [u, v, w] : ans) cout << u << ' ' << v << ' ' << w << '\n';
  return 0;
}
