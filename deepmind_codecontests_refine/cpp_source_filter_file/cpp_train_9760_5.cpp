#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  pair<int, int> a[n];
  int f, s;
  for (int i = 0; i < n; i++) {
    cin >> f;
    cin >> s;
    a[i] = make_pair(f, s);
  }
  int m;
  cin >> m;
  pair<int, int> aa[n + m];
  for (int i = 0; i < n; i++) {
    f = a[i].first;
    s = a[i].second;
    aa[i] = make_pair(f, s);
  }
  for (int i = 0 + n; i < (m + n); i++) {
    cin >> f;
    cin >> s;
    aa[i] = make_pair(f, s);
  }
  sort(aa, aa + (n + m));
  long sum = 0;
  for (int i = 0; i < (m + n); i++) {
    if (i == m + n - 1) {
      sum += aa[i].second;
    } else if (aa[i].first == aa[i + 1].first) {
      sum += max(aa[i].second, aa[i + 1].second);
      i++;
    } else {
      sum += aa[i].second;
    }
  }
  cout << sum << "\n";
  return 0;
}
