#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long w, m;
  cin >> w >> m;
  vector<int> f;
  while (m) {
    f.push_back(m % w);
    m /= w;
  }
  f.push_back(0);
  f.push_back(0);
  reverse(f.begin(), f.end());
  for (int i = f.size() - 1; i >= 0; i--) {
    if (i > 1) f[i - 1] += f[i] / w;
    f[i] %= w;
    if (f[i] == 0) continue;
    if (f[i] == 1) continue;
    if (f[i] == w - 1) {
      f[i - 1]++;
      continue;
    }
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
