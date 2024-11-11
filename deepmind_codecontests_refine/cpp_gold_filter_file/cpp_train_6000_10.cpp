#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 3;
struct Rcompare {
  bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first > rhs.first;
  }
};
struct compare {
  bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.first < rhs.first;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << 2 * (max(1, abs(a - c)) + max(1, abs(b - d)) + 2);
  return 0;
}
