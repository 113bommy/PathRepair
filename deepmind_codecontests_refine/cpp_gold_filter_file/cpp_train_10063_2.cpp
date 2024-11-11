#include <bits/stdc++.h>
using namespace std;
void ending() { exit(0); }
void killer() { exit(1); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > a(n);
  vector<int> conf(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  int x, y;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    x--, y--;
    if (a[x].first > a[y].first) swap(x, y);
    if (a[x].first != a[y].first) conf[y]++;
  }
  sort(a.begin(), a.end());
  b[0] = 0;
  for (int i = 1; i < n; i++) {
    b[i] = (a[i].first == a[i - 1].first ? b[i - 1] : i);
  }
  for (int i = 0; i < n; i++) {
    a[i].first = b[i];
    swap(a[i].first, a[i].second);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) cout << max(0, a[i].second - conf[i]) << ' ';
  ending();
  ;
}
