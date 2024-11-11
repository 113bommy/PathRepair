#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5;
const int MOD = 998244353;
int n, q, d, m, id[maxn + 3], v[maxn + 3], t[maxn + 3];
int dem[maxn + 3];
int k, res = 0;
long long tong[maxn + 3], ans[maxn + 3], a[maxn + 3];
string second, s1;
map<long long, long long> w;
vector<int> edge[maxn + 3];
template <typename T>
void answer(T x) {
  cout << x;
  exit(0);
}
bool kt(int l, int r) {
  r--;
  string tt = "";
  for (int i = l; i <= r; i++) tt += s1[i];
  if (tt == second) return false;
  while (l <= r)
    if (s1[l] == s1[r])
      l++, r--;
    else {
      res = 2;
      return false;
    }
  return true;
}
void kt1() {
  s1 = second + second[0];
  for (int i = 1; i < second.length(); ++i) {
    if (kt(i, i + second.length())) answer(1);
    s1 += second[i];
  }
}
bool kt2() {
  for (int i = 1; i < second.length() / 2; ++i)
    if (second[i] != second[0]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> second;
  if (!kt2()) answer("Impossible");
  kt1();
  if (res) answer(res);
}
