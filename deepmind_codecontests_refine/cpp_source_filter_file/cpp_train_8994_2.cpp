#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
int main() {
  fast();
  long long n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << "NO";
    return 0;
  }
  vector<long long> v;
  for (int i = 0; i < m; ++i) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  if (v[0] == 0 || v[v.size() - 1] == n) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < v.size() - 1; ++i) {
    if ((v[i + 2] - 2) == v[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
