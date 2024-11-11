#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  map<int, int> m;
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    cin >> v[i];
    m[v[i]] = 0;
  }
  int cnt = 0;
  for (auto& p : m) {
    p.second = cnt++;
  }
  int res = 0;
  for (int i = 0; i < N; i++) {
    res += (i % 2 != m[v[i]] % 2);
  }
  cout << res << endl;
}
