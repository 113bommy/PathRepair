#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K; cin >> N >> K;
  auto s = 0LL;
  vector<int> H(N); for (auto &h: H) {cin >> h; s += h;} sort(H.rbegin(), H.rend());
  for (int i = 0; i < min(K, N); ++i) s -= H[i];
  cout << s << endl;}