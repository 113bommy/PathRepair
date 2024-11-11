#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];
vector<pair<int, int>> first;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, q;
  cin >> n >> q;
  int ma = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int front = 0;
  for (int i = 1; i < n; ++i) {
    first.emplace_back(a[front], a[i]);
    if (a[i] >= a[front]) {
      b[i - 1] = a[front];
      front = i;
    } else
      b[i - 1] = a[i];
  }
  --n;
  b[n] = a[front];
  long long m;
  for (int i = 0; i < q; ++i) {
    cin >> m;
    --m;
    if (m < n)
      cout << first[m].first << ' ' << first[m].second << '\n';
    else
      cout << b[n] << ' ' << b[m % n] << '\n';
  }
  return 0;
}
