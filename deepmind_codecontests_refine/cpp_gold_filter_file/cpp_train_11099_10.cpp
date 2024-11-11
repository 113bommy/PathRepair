#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
const int SIZE = 1e6 + 10;
long long BIT[2][SIZE];
void ins(long long bit[], int x, long long v) {
  for (; x; x -= x & -x) bit[x] += v;
}
long long qq(long long bit[], int x) {
  long long res = 0;
  for (; x < SIZE; x += x & -x) res += bit[x];
  return res;
}
vector<pair<int, int> > data[2][SIZE];
int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < (M); ++i) {
    int d, f;
    scanf("%d%d", &d, &f);
    int t, c;
    scanf("%d%d", &t, &c);
    if (!f) {
      data[1][t].push_back(make_pair(d, c));
    } else {
      data[0][f].push_back(make_pair(d, c));
    }
  }
  for (int i = (1); i < (N + 1); ++i) {
    if (!((int)(data[0][i]).size()) || !((int)(data[1][i]).size()))
      return 0 * puts("-1");
    for (int j = 0; j < (2); ++j)
      sort((data[j][i]).begin(), (data[j][i]).end());
    int lt = 1;
    long long mi = INF;
    for (int j = 0; j < (((int)(data[0][i]).size())); ++j) {
      ins(BIT[0], lt - 1, -mi);
      ins(BIT[0], data[0][i][j].first - 1, mi);
      mi = min(mi, (long long)data[0][i][j].second);
      lt = data[0][i][j].first;
    }
    ins(BIT[0], lt - 1, -mi);
    ins(BIT[0], SIZE - 1, mi);
    lt = SIZE - 1;
    mi = INF;
    for (int j = ((int)(data[1][i]).size()) - 1; j >= 0; j--) {
      while (j && data[1][i][j].first == data[1][i][j - 1].first) j--;
      ins(BIT[1], (SIZE - lt) - 1, -mi);
      ins(BIT[1], (SIZE - data[1][i][j].first) - 1, mi);
      mi = min(mi, (long long)data[1][i][j].second);
      lt = data[1][i][j].first;
    }
    ins(BIT[1], (SIZE - lt) - 1, -mi);
    ins(BIT[1], SIZE - 1, mi);
  }
  long long ans = INF;
  for (int i = 2; i + K < SIZE; i++) {
    long long v = qq(BIT[0], i - 1) + qq(BIT[1], (SIZE - (i + K)));
    if (v < ans) {
      ans = v;
    }
  }
  if (ans >= INF)
    puts("-1");
  else
    printf("%I64d\n", ans);
  return 0;
}
