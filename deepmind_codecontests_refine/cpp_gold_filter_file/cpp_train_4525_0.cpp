#include <bits/stdc++.h>
using namespace std;
int main() {
  int count[2009];
  int n;
  cin >> n;
  int i, d[2009], ans = 0;
  vector<pair<int, int> > a;
  for (i = 0; i < n; i++) {
    cin >> d[i];
    a.push_back(make_pair(d[i], i));
    count[d[i]]++;
    if (count[d[i]] >= 2) ans++;
  }
  if (ans < 2)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    sort(a.begin(), a.end());
    for (i = 0; i < n; i++) cout << a[i].second + 1 << ' ';
    cout << endl;
    for (i = 1; i < n; i++)
      if (a[i].first == a[i - 1].first) {
        swap(a[i].second, a[i - 1].second);
        break;
      }
    for (i = 0; i < n; i++) cout << a[i].second + 1 << ' ';
    cout << endl;
    for (i = n - 2; i >= 0; i--)
      if (a[i].first == a[i + 1].first) {
        swap(a[i].second, a[i + 1].second);
        break;
      }
    for (i = 0; i < n; i++) cout << a[i].second + 1 << ' ';
    cout << endl;
  }
}
