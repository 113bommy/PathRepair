#include <bits/stdc++.h>
using namespace std;
const int N = 4000009;
int main() {
  int n, k;
  cin >> n >> k;
  int a[1010];
  int origin_a[1010];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    origin_a[i] = a[i];
  }
  int ans = 0;
  vector<pair<int, int> > abi;
  int tmp;
  for (int i = 1; i <= 1000; i++) {
    a[1] = i;
    ans = 0;
    for (int j = 2; j <= n; j++) {
      a[j] = a[j - 1] + k;
    }
    for (int j = 1; j <= n; j++) {
      if (origin_a[j] != a[j]) {
        ans++;
        a[j] = origin_a[j];
      }
    }
    abi.push_back(make_pair(ans, i));
  }
  int seed = 0;
  ans = 1111;
  for (int i = 0; i < abi.size(); i++) {
    if (ans > abi[i].first) {
      ans = abi[i].first;
      seed = abi[i].second;
    }
  }
  cout << ans << endl;
  if (seed != origin_a[1]) {
    if (seed > origin_a[1]) {
      cout << "+ " << 1 << " " << seed - origin_a[1];
    } else
      cout << "- " << 1 << " " << origin_a - seed;
    cout << endl;
  }
  a[1] = seed;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + k;
    if (a[i] > origin_a[i]) {
      cout << "+ " << i << " " << a[i] - origin_a[i] << endl;
    } else if (a[i] < origin_a[i]) {
      cout << "- " << i << " " << origin_a[i] - a[i] << endl;
    }
  }
  return 0;
}
