#include <bits/stdc++.h>
using namespace std;
const unsigned int INF = 2 * int(1e9) + 5;
const long long INFll = 1ll * INF * INF;
const int MOD = 1000000007;
vector<int> a, u;
void make(vector<int>& p) {
  vector<int> b(p.size());
  vector<int> u_(p.size());
  for (int i = 0; i < p.size(); ++i) b[i] = a[p[i]], u_[i] = u[p[i]];
  for (int i = 0; i < b.size(); ++i) {
    if (u_[i]) {
      int r = i;
      while (r < b.size() && u_[r]) r++;
      r--;
      int lb = -INF;
      int rb = INF;
      if (r < b.size() - 1) rb = b[r + 1];
      if (i) lb = b[i - 1];
      int l = r - i + 1;
      if (1ll * rb - lb - 1 < l) {
        cout << "Incorrect sequence";
        exit(0);
      }
      int L = -l / 2;
      int R = L + l - 1;
      if (R >= rb) R = rb - 1, L = R - l + 1;
      if (L <= lb) L = lb + 1, R = L + l - 1;
      for (int j = i; j <= r; ++j) b[j] = L++;
      i = r;
    }
  }
  for (int i = 1; i < b.size(); ++i)
    if (b[i] < b[i - 1]) {
      cout << "Incorrect sequence";
      exit(0);
    }
  for (int i = 0; i < b.size(); ++i) a[p[i]] = b[i];
}
int get(const string& s) {
  bool f = 0;
  if (s[0] == '-') f = 1;
  int res = 0;
  for (int i = f; i < s.size(); ++i) res = res * 10 + s[i] - '0';
  if (f) res *= -1;
  return res;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  a.resize(n);
  u.resize(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "?")
      u[i] = 1;
    else
      a[i] = get(s);
  }
  for (int i = 0; i < k; ++i) {
    int j = i;
    vector<int> b;
    while (j < n) b.push_back(j), j += k;
    make(b);
  }
  for (int i = 0; i < n; ++i) cout << a[i] << " ";
  return 0;
}
