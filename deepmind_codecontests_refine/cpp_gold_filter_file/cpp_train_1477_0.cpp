#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 2 * acos(0);
const int MAXN = 1e6 + 6;
int n;
long long C[MAXN];
void input() {
  int u, v, w, x, y, qtype;
  cin >> n;
}
void preprocess() {
  for (int i = 2; i <= 50000; ++i) C[i] = 1ll * i * (i - 1) / 2;
}
void process(int itest) {
  int u, v, w, x, y, qtype;
  vector<int> vec;
  for (int i = 50000; i >= 2 && n > 0; --i) {
    while (n >= C[i]) {
      n -= C[i];
      vec.push_back(i);
    }
  }
  vec.push_back(0);
  cout << "1";
  for (int i = vec.size() - 2; i >= 0; --i) {
    v = vec[i] - vec[i + 1];
    for (int j = (1); j <= (v); ++j) cout << "3";
    cout << "7";
  }
  cout << "\n";
}
void oneTest() {
  input();
  preprocess();
  process(0);
}
void multiTest() {
  int t;
  cin >> t;
  preprocess();
  for (int it = 1; it <= t; ++it) {
    input();
    process(it);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  multiTest();
  return 0;
}
