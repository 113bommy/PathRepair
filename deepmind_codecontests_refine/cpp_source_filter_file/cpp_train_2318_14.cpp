#include <bits/stdc++.h>
using namespace std;
const long long max_n = 1e6 + 100;
const long long max_k = 21;
long long n, m, k;
string s, t;
pair<long long, long long> a[max_n];
vector<string> S, T;
long long Right[(1LL << 21)], Left[(1LL << 21)];
void fill(bool is_s) {
  if (is_s)
    S.push_back(s);
  else
    T.push_back(t);
  vector<long long> p, inv_p;
  for (long long i = 0; i < k; i++) {
    p.push_back(i);
    inv_p.push_back(i);
  }
  for (long long i = 0; i < n; i++) {
    p[inv_p[a[i].first]] = a[i].second;
    p[inv_p[a[i].second]] = a[i].first;
    string current = "";
    for (long long i = 0; i < k; i++) {
      inv_p[p[i]] = i;
      if (is_s)
        current.push_back(s[p[i]]);
      else
        current.push_back(t[p[i]]);
    }
    if (is_s)
      S.push_back(current);
    else
      T.push_back(current);
  }
  return;
}
void fill_right(long long mask, long long idx) {
  if (mask == 0) return;
  if (Right[mask] != -1) return;
  Right[mask] = idx;
  for (long long j = 0; j < k; j++)
    if (mask & (1LL << j)) {
      fill_right(mask ^ (1LL << j), idx);
    }
  return;
}
void fill_left(long long mask, long long idx) {
  if (mask == 0) return;
  if (Left[mask] != (long long)(1e9)) return;
  Left[mask] = idx;
  for (long long j = 0; j < k; j++)
    if (mask & (1LL << j)) {
      fill_left(mask ^ (1LL << j), idx);
    }
  return;
}
long long number_of_common_bits(string s, string t) {
  long long ans = 0;
  for (long long i = 0; i < k; i++)
    if (s[i] == t[i]) ans++;
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  memset(Right, -1, sizeof(Right));
  for (long long i = 0; i < (1LL << 21); i++) Left[i] = 1e9;
  cin >> s >> t;
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    a[i].first--;
    a[i].second--;
  }
  fill(1);
  fill(0);
  for (long long i = n; i >= 0; i--) {
    long long num = 0;
    for (long long j = 0; j < k; j++)
      if (T[i][j] == '1') {
        num += (1LL << j);
      }
    fill_right(num, i);
  }
  for (long long i = 0; i <= n; i++) {
    long long num = 0;
    for (long long j = 0; j < k; j++)
      if (S[i][j] == '1') {
        num += (1LL << j);
      }
    fill_left(num, i);
  }
  long long ans = 0;
  pair<long long, long long> index(-1, -1);
  for (long long mask = 0; mask < (1LL << k); mask++) {
    if (Right[mask] - Left[mask] >= m) {
      long long t = number_of_common_bits(S[Left[mask]], T[Right[mask]]);
      if (t >= ans) {
        ans = t;
        index = {Left[mask] + 1, Right[mask]};
      }
    }
  }
  cout << ans << endl;
  cout << index.first << " " << index.second << endl;
  return 0;
}
