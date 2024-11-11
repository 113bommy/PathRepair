#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  vector<pair<int, int>> a;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x == 1)
      a.push_back(make_pair(y, i + 1));
    else
      b.push_back(make_pair(y, i + 1));
  }
  vector<int> sum1(a.size() + 1);
  vector<int> sum2(b.size() + 1);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  for (int i = 1; i <= a.size(); i++) sum1[i] = sum1[i - 1] + a[i - 1].first;
  for (int i = 1; i <= b.size(); i++) sum2[i] = sum2[i - 1] + b[i - 1].first;
  int ans = 0, ind1 = 0, ind2 = 0;
  for (int i = 0; i < a.size() + 1 && i <= v; i++) {
    int freev = min((v - i) / 2, (int)b.size());
    if (sum1[i] + sum2[freev] > ans) {
      ans = sum1[i] + sum2[freev];
      ind1 = i, ind2 = freev;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < ind1; i++) cout << a[i].second << " ";
  for (int i = 0; i < ind2; i++) cout << b[i].second << " ";
  return 0;
}
