#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
using pii = pair<int, int>;
using l = long;
using ll = long long;
using ull = unsigned long long;
void solve();
int main() {
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  { solve(); }
  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  const auto duration = duration_cast<milliseconds>(t2 - t1).count();
  cout.flush();
  cerr << "--------------" << endl;
  cerr << "Elapsed Time: " << duration << "ms" << endl;
  cerr << "--------------" << endl;
  ;
}
int n;
constexpr int S = 505;
char M[S][S] = {{0}};
void solve() {
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      const char c = M[i][j];
      if (c == 'X' && M[i - 1][j + 1] == c && M[i + 1][j - 1] == c &&
          M[i - 1][j + 1] == c && M[i - 1][j - 1] == c)
        ans++;
    }
  }
  cout << ans << endl;
}
