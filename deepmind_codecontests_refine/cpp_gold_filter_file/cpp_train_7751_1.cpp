#include <bits/stdc++.h>
const int N = 100005;
const int MOD = 1000000003;
using namespace std;
int a[N];
pair<int, int> bit[N], F2[N], F1[N];
int n;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
void upd1(int i, pair<int, int> f) {
  for (i++; i < N; i += i & -i) {
    if (bit[i].first < f.first)
      bit[i] = f;
    else if (bit[i].first == f.first)
      add(bit[i].second, f.second);
  }
}
pair<int, int> get1(int i) {
  pair<int, int> s(0, 0);
  for (i++; i; i -= i & -i) {
    if (bit[i].first > s.first)
      s = bit[i];
    else if (bit[i].first == s.first)
      add(s.second, bit[i].second);
  }
  return make_pair(s.first + 1, s.second);
}
void upd2(int i, pair<int, int> f) {
  for (i++; i; i -= i & -i) {
    if (bit[i].first < f.first)
      bit[i] = f;
    else if (bit[i].first == f.first)
      add(bit[i].second, f.second);
  }
}
pair<int, int> get2(int i) {
  pair<int, int> s(0, 0);
  for (i++; i < N; i += i & -i) {
    if (bit[i].first > s.first)
      s = bit[i];
    else if (bit[i].first == s.first)
      add(s.second, bit[i].second);
  }
  return make_pair(s.first + 1, s.second);
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  upd1(0, make_pair(0, 1));
  pair<int, int> ans(0, 0);
  for (int i = (1); i <= (n); i++) {
    F1[i] = get1(a[i] - 1);
    upd1(a[i], F1[i]);
    if (ans.first < F1[i].first)
      ans = F1[i];
    else if (ans.first == F1[i].first)
      add(ans.second, F1[i].second);
  }
  memset(bit, 0, sizeof bit);
  upd2(N - 2, make_pair(0, 1));
  for (int i = (n); i >= (1); i--) {
    F2[i] = get2(a[i] + 1);
    upd2(a[i], F2[i]);
  }
  for (int i = (1); i <= (n); i++) {
    pair<int, int> now(F1[i].first + F2[i].first - 1,
                       (long long)F1[i].second * F2[i].second % MOD);
    if (now.first < ans.first)
      cout << 1;
    else if (now.second != ans.second)
      cout << 2;
    else
      cout << 3;
  }
  return 0;
}
