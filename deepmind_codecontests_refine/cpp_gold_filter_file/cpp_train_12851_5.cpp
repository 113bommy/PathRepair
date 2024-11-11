#include <bits/stdc++.h>
using namespace std;
int e[1000];
int main() {
  {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  }
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  pair<int, int> mx;
  mx.first = -1;
  mx.second = -1;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) {
    int c = ceil(double(v[i]) / m);
    if (c >= mx.first) {
      mx.first = c;
      mx.second = i;
    }
  }
  cout << mx.second + 1;
}
