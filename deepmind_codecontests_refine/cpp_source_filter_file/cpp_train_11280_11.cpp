#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
long double PI = 3.14159265358979323846264338327950;
const int N = 1001;
int n, m, k;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  vector<int> res;
  for (int i = 0; i < k; i++) res.push_back(1);
  res.push_back(n);
  for (int i = 0; i < k - 1; i++) res.push_back(n + 1);
  if (n + m >= res[(int)res.size() - 1] + n - 1)
    res.push_back(res[(int)res.size() - 1] + n - 1);
  cout << (int)res.size() << "\n";
  for (auto i : res) cout << i << " ";
  return 0;
}
