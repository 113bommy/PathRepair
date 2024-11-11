#include <bits/stdc++.h>
using namespace std;
vector<pair<int, string>> buildS(int M) {
  vector<pair<int, string>> res;
  res.push_back({M - 1, "D"});
  res.push_back({1, "R"});
  res.push_back({M - 1, "LUR"});
  return res;
}
void solve() {
  int N, M, K;
  cin >> M >> N >> K;
  int roads = 4 * N * M - 2 * N - 2 * M;
  stringstream ss;
  int steps = 0;
  if (K > roads) {
    cout << "NO" << endl;
    return;
  } else if (N == 1) {
    cout << "YES" << endl;
    steps = 1;
    int c = min(K, M - 1);
    ss << c << " R" << endl;
    K -= c;
    c = K;
    if (c != 0) {
      ss << c << " L" << endl;
      steps++;
    }
    cout << steps << endl;
    cout << ss.str();
    return;
  } else if (M == 1) {
    cout << "YES" << endl;
    steps = 1;
    int c = min(K, N - 1);
    ss << c << " D" << endl;
    K -= c;
    c = K;
    if (c != 0) {
      ss << c << " U" << endl;
      steps++;
    }
    cout << steps << endl;
    cout << ss.str();
    return;
  }
  cout << "YES" << endl;
  vector<pair<int, string>> s = buildS(M);
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < s.size(); j++) {
      auto p = s[j];
      int c = min(p.first, K / (int)p.second.length());
      if (c != 0) {
        ss << c << " " << p.second << endl;
        steps++;
      }
      K -= c * p.second.length();
      if (c != p.first && K < p.second.length() && K != 0) {
        ss << 1 << " " << p.second.substr(0, K) << endl;
        K = 0;
        steps++;
      }
      if (K == 0) break;
    }
    if (K == 0) break;
  }
  int c = min(K, M - 1);
  K -= c;
  if (c > 0) {
    ss << c << " "
       << "D" << endl;
    steps++;
  }
  c = min(K, M - 1);
  K -= c;
  if (c > 0) {
    ss << c << " "
       << "U" << endl;
    steps++;
  }
  c = min(K, N - 1);
  K -= c;
  if (c > 0) {
    ss << c << " "
       << "L" << endl;
    steps++;
  }
  cout << steps << endl;
  cout << ss.str();
}
int main() {
  int T = 1;
  while (T--) solve();
}
