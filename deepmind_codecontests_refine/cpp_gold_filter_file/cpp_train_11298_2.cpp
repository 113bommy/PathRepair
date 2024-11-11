#include <bits/stdc++.h>
using namespace std;
bool pr(const pair<int, string>& p, const pair<int, string>& q) {
  return p.first < q.first;
}
int main() {
  int i;
  int n;
  cin >> n;
  pair<int, string> a[100];
  for (i = 0; i < n; ++i) {
    string s;
    cin >> a[i].second >> s;
    if (false) {
    } else if (s == "captain") {
      a[i].first = 10;
    } else if (s == "rat") {
      a[i].first = 7;
    } else if (s == "man") {
      a[i].first = 9;
    } else {
      a[i].first = 8;
    }
  }
  stable_sort(a, a + n, pr);
  for (i = 0; i < n; ++i) cout << a[i].second << endl;
  return 0;
}
