#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  ;
  vector<int> v(n), a;
  for (auto &i : v) cin >> i;
  ;
  map<int, vector<int>> m;
  a = v;
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 0; i < n; i++) m[v[i]].push_back(i + 1);
  long long x = 0, c = 0;
  for (int i = 0; i < n; i++) {
    c += (1 + (x * v[i]));
    x++;
  }
  cout << c << "\n";
  for (int i = 0; i < n; i++) {
    cout << m[a[i]].back() << " ";
    m[a[i]].pop_back();
  }
  return 0;
}
