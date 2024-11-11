#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
void pre() {}
vector<int> p;
pair<long long int, long long int> arr[1000 + 1];
long long n, l;
long double dp[1001];
long long path[1000 + 1];
bool check(double a) {
  for (int i = 0; i < 1001; i++) {
    dp[i] = 1000000000;
  }
  dp[0] = 0.0;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (dp[j] > dp[i] + sqrt(abs(l - arr[j].first + arr[i].first)) -
                      a * arr[j].second) {
        dp[j] = dp[i] + sqrt(abs(l - arr[j].first + arr[i].first)) -
                a * arr[j].second;
        path[j] = i;
      }
    }
  }
  if (dp[n] <= 0) {
    int curr = n;
    p.clear();
    while (curr != 0) {
      p.push_back(curr);
      curr = path[curr];
    }
    return true;
  }
  return false;
}
void solve() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].first;
    cin >> arr[i].second;
  }
  sort(arr + 1, arr + n);
  long double start = 0.0, end = 1000.0, mid = 0.0;
  while ((end - start) > 0.000001) {
    mid = (start + end) / 2.0;
    if (check(mid)) {
      end = mid;
    } else {
      start = mid;
    }
  }
  reverse(p.begin(), p.end());
  for (int i : p) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  long long int num = 1;
  for (long long int i = 0; i < num; i++) {
    solve();
  }
}
