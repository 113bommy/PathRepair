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
int solve(int x) {
  if (x < 4 || x == 5 || x == 7 || x == 11) {
    return -1;
  }
  if (x % 4 == 0) {
    return x / 4;
  }
  if (x % 4 == 2) {
    return x / 4;
  }
  if (x % 4 == 1) {
    return x / 4 - 1;
  }
  return x / 4 - 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    int x;
    cin >> x;
    cout << solve(x) << "\n";
  }
  return 0;
}
