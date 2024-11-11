#include <bits/stdc++.h>
using namespace std;
void read(long long a = 0) {
  freopen("in", "r", stdin);
  if (a) freopen("out", "w", stdout);
}
using namespace std;
int n, m, k, TC;
int arr[100009], dp[100009], last[100009];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  set<pair<int, int> > se;
  cin >> n;
  cin >> k;
  se.insert(make_pair(k, 0));
  se.insert(make_pair(-1, -1));
  se.insert(make_pair(100009 * 1000000007, -1));
  long long ans = 0;
  while (--n) {
    cin >> k;
    set<pair<int, int> >::iterator it = se.lower_bound(make_pair(k, 1252160));
    set<pair<int, int> >::iterator it1 = it;
    it1--;
    int l = max(it->second, it1->second);
    if (it->second > it1->second)
      cout << it->first;
    else
      cout << it1->first;
    cout << "\n";
    se.insert(make_pair(k, l + 1));
  }
}
