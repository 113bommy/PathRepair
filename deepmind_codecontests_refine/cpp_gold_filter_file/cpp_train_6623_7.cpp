#include <bits/stdc++.h>
using namespace std;
int N, M, T;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int i, j, k;
  cin >> N >> M >> k;
  vector<int> v;
  int sum = 0;
  while (N--) {
    cin >> j;
    sum += j;
    v.push_back((j));
  }
  i = v.size() - 1;
  while (M--) {
    sum -= v[i];
    sum += k;
    i--;
  }
  cout << sum << '\n';
  return 0;
}
