#include <bits/stdc++.h>
using namespace std;
pair<long long, pair<long long, long long> > a[300000];
int main() {
  long long k, i, j, p;
  cin >> k;
  long long cnt = 0, n, sum;
  for (i = 0; i < k; i++) {
    cin >> n;
    sum = 0;
    for (j = 0; j < n; j++) {
      cin >> p;
      a[cnt].first = p;
      sum += p;
      a[cnt].second.first = i;
      a[cnt].second.second = j;
      cnt++;
    }
    for (j = cnt - n; j < cnt; j++) {
      a[j].first -= sum;
    }
  }
  sort(a, a + cnt);
  for (i = 0; i < cnt - 1; i++) {
    if (a[i].first == a[i + 1].first) {
      if (a[i].second.first != a[i + 1].second.first) {
        cout << "YES\n";
        cout << a[i].second.first + 1 << " " << a[i].second.second + 1 << endl;
        cout << a[i + 1].second.first + 1 << " " << a[i + 1].second.second + 1
             << endl;
        return 0;
      }
    }
  }
  cout << "NO\n";
}
