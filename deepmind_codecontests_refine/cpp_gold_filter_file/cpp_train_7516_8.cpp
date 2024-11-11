#include <bits/stdc++.h>
using namespace std;
long long p[51];
long long dp[51];
int pp[51];
int sz[51];
int get(int a) {
  while (pp[a] != a) a = pp[a];
  return a;
}
void merge(int a, int b) {
  a = get(a);
  b = get(b);
  if (sz[a] > sz[b]) swap(a, b);
  pp[a] = b;
  sz[b] += sz[a];
}
long long mul(long long a, long long b) {
  long double x = 1.0 * a * b;
  if (2000000000000000000LL >= x) return a * b;
  return 2000000000000000000LL;
}
long long add(long long a, long long b) {
  long double x = 0.0 + a + b;
  if (2000000000000000000LL >= x) return a + b;
  return 2000000000000000000LL;
}
vector<int> buildHead(int start, int ff, long long k) {
  if (ff == 1) {
    vector<int> vec;
    vec.push_back(start + ff);
    return vec;
  }
  bool used[51];
  for (int i = 0; i <= ff; i++) pp[i] = i, sz[i] = 1, used[i] = false;
  vector<int> vec;
  vec.push_back(ff);
  merge(ff, 1);
  used[ff] = true;
  for (int i = 2; i <= ff; i++) {
    if (i == ff) {
      for (int j = 1; j <= ff; j++)
        if (!used[j]) {
          vec.push_back(j);
          break;
        }
      break;
    }
    for (int j = 1; j <= ff; j++) {
      if (!used[j] && i != j && get(j) != get(i)) {
        if (k > p[ff - i + 1])
          k -= p[ff - i + 1];
        else {
          used[j] = true;
          vec.push_back(j);
          merge(i, j);
          break;
        }
      }
    }
  }
  for (int i = 0; i < vec.size(); i++) vec[i] += start;
  return vec;
}
vector<int> solve(int start, int n, long long k) {
  if (n == 1) {
    vector<int> vec;
    vec.push_back(1 + start);
    return vec;
  }
  if (n == 0) {
    vector<int> vec;
    return vec;
  }
  int a;
  for (a = 1; a <= n; a++) {
    if (mul(p[a], dp[n - a]) < k)
      k -= mul(p[a], dp[n - a]);
    else
      break;
  }
  long long ff = (k + dp[n - a] - 1) / dp[n - a];
  vector<int> vec = buildHead(start, a, ff);
  vector<int> res =
      solve(start + a, n - a, (k % dp[n - a]) == 0 ? dp[n - a] : k % dp[n - a]);
  for (int i = 0; i < res.size(); i++) {
    vec.push_back(res[i]);
  }
  return vec;
}
int main() {
  int t;
  cin >> t;
  int n;
  long long k;
  while (t--) {
    cin >> n >> k;
    p[0] = 1;
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    for (int i = 4; i <= 50; i++) p[i] = mul(p[i - 1], i - 2);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
      dp[i] = 0;
      for (int j = 1; j <= i; j++) dp[i] = add(dp[i], mul(dp[i - j], p[j]));
    }
    if (k > dp[n]) {
      cout << -1 << endl;
      continue;
    }
    vector<int> ans = solve(0, n, k);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
