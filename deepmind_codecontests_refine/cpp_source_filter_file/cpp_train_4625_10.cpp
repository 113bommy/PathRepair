#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double EPS = 1e-9;
const int INF = 1e9 + 7;
const long long LINF = 8e18 + 7;
const int N = 1e6 + 7;
long long f[N];
void upd(int i, int d) {
  for (; i < N; i |= i + 1) {
    f[i] += d;
  }
}
long long get(int r) {
  long long res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) {
    res += f[r];
  }
  return res;
}
int find(int x) {
  int l = 0, r = N - 7;
  while (r - l > 1) {
    int m = (r + l) / 2;
    if (get(m) >= x) {
      r = m;
    } else {
      l = m;
    }
  }
  for (int i = l; i <= r; ++i) {
    if (get(i) == x) {
      return i;
    }
  }
}
int s[N];
int E = 0;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < (int)(m); ++i) {
    cin >> a[i];
  }
  for (int _ = 0; _ < (int)(n); ++_) {
    int x;
    cin >> x;
    x++;
    if (!x) {
      vector<int> us;
      for (int i = 0; i < (int)(m); ++i) {
        if (get(E) < a[i]) {
          break;
        }
        int j = find(a[i]);
        us.push_back(j);
        s[j] = 0;
      }
      for (int i : us) {
        upd(i, -1);
      }
      continue;
    }
    upd(E, 1);
    s[E++] = x;
  }
  vector<int> ans;
  for (int i = 0; i < (int)(E); ++i) {
    if (s[i]) ans.push_back(s[i] - 1);
  }
  if (ans.empty()) {
    cout << "Poor stack!" << '\n';
    return 0;
  }
  for (int i : ans) {
    cout << ans[i];
  }
}
