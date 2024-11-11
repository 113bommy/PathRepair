#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 6;
const long long INF = 1e18 + 4;
const int MOD = 1e9 + 7;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;
set<int> st;
map<int, int> cnt;
int a[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= k; i++) cnt[a[i]]++;
  for (int i = 1; i <= k; i++)
    if (cnt[a[i]] == 1) st.insert(-a[i]);
  for (int i = k; i <= n; i++) {
    if (!st.size())
      cout << "Nothing" << endl;
    else
      cout << -(*st.begin()) << endl;
    int pl = i - k + 1;
    cnt[a[pl]]--;
    cnt[a[i + 1]]++;
    if (cnt[a[pl]] == 0) st.erase(-a[pl]);
    if (cnt[a[pl]] == 1) st.insert(-a[pl]);
    if (cnt[a[i + 1]] == 1) st.insert(-a[i + 1]);
    if (cnt[a[i + 1]] == 2) st.erase(-a[i + 1]);
  }
  return 0;
}
