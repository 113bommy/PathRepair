#include <bits/stdc++.h>
#pragma warning(disable : 4996);
const double pi = 3.14159265358979;
const double EPS = 1e-6;
const int INF = 1e9;
const int N = 1e5;
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool inc = true;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i != 0 && a[i - 1] >= a[i]) inc = false;
  }
  if (inc) {
    cout << 0;
    return 0;
  }
  vector<pair<int, pair<int, int>>> ans;
  long long total = 0;
  int need = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    int temp = 0;
    a[i] += total;
    while ((a[i] + temp) % n != need) temp++;
    need--;
    total += temp;
    a[i] += temp;
    ans.push_back(make_pair(1, make_pair(i + 1, temp)));
  }
  ans.push_back(make_pair(2, make_pair(n, n)));
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second.first << ' '
         << ans[i].second.second << endl;
}
