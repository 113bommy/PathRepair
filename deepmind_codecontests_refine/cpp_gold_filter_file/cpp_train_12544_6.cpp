#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
vector<pair<pair<int, int>, int> > v[2010];
pair<pair<int, int>, int> OAO[N];
int main() {
  int a, b;
  scanf("%d", &n);
  for (int t = 0; t < n; t++) {
    scanf("%d%d", &a, &b);
    OAO[t] = make_pair(make_pair(a, b), t + 1);
  }
  sort(OAO, OAO + n);
  for (int t = 0; t < n; t++) {
    int a = (OAO[t].first).first;
    int b = (OAO[t].first).second;
    int index = OAO[t].second;
    int which = b / 980;
    v[which].push_back(make_pair(make_pair(a, b), index));
  }
  int cnt = 0;
  for (int i = 0; i <= 2000; i++) {
    sort(v[i].begin(), v[i].end());
    int size = v[i].size();
    for (int j = 0; j < size; j++) {
      cnt++;
      printf("%d%c", v[i][j].second, cnt == n ? '\n' : ' ');
    }
  }
}
