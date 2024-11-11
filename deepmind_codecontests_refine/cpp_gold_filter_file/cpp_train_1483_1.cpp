#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> l(m), p(m);
  for (auto& i : l) {
    cin >> i;
  }
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    if (l[i] > n - i) {
      cout << "-1\n";
      return 0;
    }
    sum += l[i];
    p[i] = i + 1;
  }
  if (sum < n) {
    cout << "-1\n";
    return 0;
  }
  p.push_back(n + 1);
  for (int i = m - 1; i >= 0; --i) {
    if (p[i] + l[i] - 1 < p[i + 1] - 1) {
      p[i] = p[i + 1] - l[i];
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << p[i] << ' ';
  }
  cout << endl;
}
