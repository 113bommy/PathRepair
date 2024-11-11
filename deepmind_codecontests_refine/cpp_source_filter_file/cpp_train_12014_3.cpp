#include <bits/stdc++.h>
using namespace std;
const int MAX = INT_MAX;
const long long MOD = 1e9 + 7;
const int TEST_MODE = 0;
int n;
vector<bool> used;
vector<int> v;
void calc() {
  used[0] = used[1] = true;
  for (int i = 2; i <= 1e7; ++i) {
    if (!used[i]) {
      v.push_back(i);
      int j = i + i;
      while (j < 1e5 + 1) {
        used[j] = true;
        j += i;
      }
    }
  }
}
void solve() {
  cin >> n;
  used.resize(1e7 + 1, 0);
  calc();
  for (int i = 0; i < n; ++i) {
    cout << v[i] << ' ';
  }
}
void test() {
  while (TEST_MODE) {
    solve();
  }
}
int main() {
  if (TEST_MODE) {
    test();
  } else {
    solve();
  }
  return 0;
}
