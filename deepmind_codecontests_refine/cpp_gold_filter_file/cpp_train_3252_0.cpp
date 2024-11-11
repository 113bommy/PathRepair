#include <bits/stdc++.h>
using namespace std;
const int f[3][4] = {
    {0, 1, 2, 3},
    {0, 2, 3, 1},
    {0, 3, 1, 2},
};
int64_t g(int64_t n) {
  int cat = (n % 3 - 1 + 3) % 3;
  int basei;
  for (basei = 0; (1LL << basei) <= n; basei += 2)
    ;
  basei -= 2;
  n = (n - (1LL << basei)) / 3;
  vector<int> a;
  while (n > 0) {
    a.push_back(n % 4);
    n /= 4;
  }
  int64_t result = (int64_t)(cat + 1) << basei;
  for (int i = 0; i < a.size(); ++i) {
    result |= (int64_t)f[cat][a[i]] << i * 2;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int64_t n;
    cin >> n;
    cout << g(n) << endl;
  }
}
