#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, t, ans, res, sum, mn = 1e9, cnt, mx, k, z, mnn = 1e9, mxx,
                                        b = 1, i, r;
string s1, s3, s2, s;
set<int> st;
pair<int, int> p;
vector<int> v, v1, v3, v4, v2;
map<char, long long> mp, mpp;
char c, d, a;
bool tr = false, fl = false;
int used[10001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  ans = b[0];
  cnt = a[0];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans |= b[j];
      cnt |= a[j];
      mx = max(mx, cnt);
      mxx = max(mxx, ans);
    }
  }
  if (mx + mxx <= 0)
    cout << cnt + ans;
  else
    cout << mx + mxx;
}
