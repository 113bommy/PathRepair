#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5;
long long tav(long long n, long long k) {
  if (k == 0) {
    return 1;
  }
  long long x = tav(n, k / 2);
  if (k % 2 == 0) {
    return x * x;
  } else {
    return x * x * n;
  }
}
long long ans[MAX_N];
vector<long long> v;
void solve() {
  long long n, h, counter = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h;
    v.push_back(h);
  }
  sort(v.begin(), v.end());
  long long x = n / 2, y = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans[i] = v[x];
      x++;
    } else {
      ans[i] = v[y];
      y++;
    }
  }
  for (int i = 1; i < n - 1; i++) {
    if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) {
      counter++;
      i++;
    }
  }
  cout << counter << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
