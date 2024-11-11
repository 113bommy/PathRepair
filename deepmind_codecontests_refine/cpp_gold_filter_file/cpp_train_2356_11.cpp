#include <bits/stdc++.h>
using namespace std;
bool myComp(int i, int j) { return i > j; }
const int mod = 1000000007;
vector<vector<int>> ed = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
  int n, a;
  cin >> n;
  vector<int> in(n, 0);
  int cnt = 0;
  for (int i = 0; i < n; ++i) cin >> a, in[i] = a;
  for (int i = 1; i < n - 1; ++i)
    if ((in[i] < in[i - 1] && in[i] < in[i + 1]) ||
        (in[i] > in[i - 1] && in[i] > in[i + 1]))
      ++cnt;
  cout << cnt << endl;
  return 0;
}
