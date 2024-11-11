#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100100;
const int INF = 0x7f7f7f7f;
const double eps = 1e-8;
const double pi = 3.1415926535897932384626433832795;
int s[Maxn];
int sum(int x);
void insert(int x, int det);
int lowbit(int x);
int main() {
  bool flags;
  int t1, t2;
  int L, b, f, n;
  map<int, pair<int, int> > mp;
  ios::sync_with_stdio(0);
  cin >> L >> b >> f;
  cin >> n;
  for (int i = 0; i < n; i++) {
    flags = false;
    cin >> t1 >> t2;
    if (t1 == 1) {
      if (t2 <= L && sum(t2 + f) == 0) {
        cout << 0 << endl;
        for (int k = 1; k <= t2; k++) insert(k, 1);
        mp.insert(make_pair(i + 1, pair<int, int>(1, t2)));
        continue;
      }
      for (int j = 2; j <= L; j++)
        if (j + t2 + b - 1 <= L && sum(j - 1) == sum(j + t2 + b + f - 1)) {
          for (int k = j + b; k < j + b + t2; k++) insert(k, 1);
          cout << j + b - 1 << endl;
          mp.insert(make_pair(i + 1, pair<int, int>(j + b, t2)));
          flags = true;
          break;
        }
      if (!flags) cout << -1 << endl;
    } else if (t1 == 2) {
      pair<int, int> it = mp.find(t2)->second;
      for (int j = it.first; j < it.first + it.second; j++) insert(j, -1);
    }
  }
  return 0;
}
int sum(int x) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) res += s[i];
  return res;
}
void insert(int x, int det) {
  for (int i = x; i <= Maxn; i += lowbit(i)) s[i] += det;
}
int lowbit(int x) { return x & (-x); }
