#include <bits/stdc++.h>
using namespace std;
const long long MOD = (1e9) + 7;
const long double EPS = 0.0000001;
const int N = 500000 + 100;
vector<int> v[N];
int solve(int idx) {
  int sz = v[idx].size();
  for (int i = 1; i < sz; i++) {
    v[idx][i] = max(v[idx][i - 1] + v[idx][i], v[idx][i]);
  }
  int mx = 0;
  for (int i = 0; i < sz; i++) mx = max(mx, v[idx][i]);
  return mx;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int c;
  cin >> c;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int csum[n + 1];
  int lst[N + 1];
  for (int i = 0; i <= N; i++) lst[i] = 0;
  int cnt[N];
  for (int i = 0; i < N; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++) cnt[arr[i]]++;
  csum[0] = 0;
  for (int i = 1; i <= n; i++) csum[i] = csum[i - 1] + (arr[i] == c);
  for (int i = 1; i <= n; i++) {
    cnt[arr[i]]--;
    if (lst[arr[i]] == 0) {
      v[arr[i]].push_back(-csum[i] + csum[0]);
    } else {
      v[arr[i]].push_back(-csum[i] + csum[lst[arr[i]]]);
    }
    v[arr[i]].push_back(1);
    if (cnt[arr[i]] == 0) v[arr[i]].push_back(-csum[n] + csum[i]);
    lst[arr[i]] = i;
  }
  int ans = csum[n];
  for (int i = 1; i <= N; i++) {
    if (i == c) continue;
    ans = max(ans, ans + solve(i));
  }
  cout << ans << endl;
  return 0;
}
