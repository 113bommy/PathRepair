#include <bits/stdc++.h>
using namespace std;
const int MODULO = 1000000007;
const int INF = 100000000;
int d[50];
int c[10000];
pair<int, int> make_index(int x) {
  int a = 0;
  while (d[a + 1] < x) a++;
  return pair<int, int>(a + 1, x - d[a] + 1);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) cin >> d[i + 1];
  for (int i = 1; i <= n; i++) d[i] += d[i - 1];
  int m = d[n];
  for (int i = 0; i < (d[n]); i++) cin >> c[i];
  vector<pair<pair<int, int>, pair<int, int> > > ans;
  for (int i = 0; i < (m); i++) {
    int idx = find(c + i, c + m, i + 1) - c;
    pair<int, int> p = make_index(i);
    pair<int, int> q = make_index(idx);
    swap(c[i], c[idx]);
    if (p != q) ans.push_back(pair<pair<int, int>, pair<int, int> >(p, q));
  }
  cout << ans.size() << endl;
  for (int i = 0; i < (((int)(ans).size())); i++) {
    printf("%d %d %d %d\n", ans[i].first.first, ans[i].first.second,
           ans[i].second.first, ans[i].second.second);
  }
  return 0;
}
