#include <bits/stdc++.h>
using namespace std;
const long long int LLINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const double EPS = 1e-10;
const double PI = acos(-1);
const int SIZE = 200005;
int N, M;
vector<pair<int, int> > vp[SIZE];
pair<int, int> qu[SIZE];
int pn[SIZE];
long long int ans[SIZE], cnt[SIZE];
int flag[SIZE];
void init() {
  for (int i = 0; i < SIZE; i++) {
    vp[i].clear();
    pn[i] = i;
    cnt[i] = 1;
    flag[i] = 0;
    ans[i] = 0;
  }
}
bool com(pair<int, int> a, pair<int, int> b) {
  if (a.first < b.first) return true;
  if (a.first == b.first) {
    if (a.second < b.second) return true;
  }
  return false;
}
int root(int indx) {
  if (indx == pn[indx]) return indx;
  return pn[indx] = root(pn[indx]);
}
int main() {
  int a, b, c;
  int mx = 0;
  init();
  scanf("%d %d", &N, &M);
  for (int i = 1; i < N; i++) {
    scanf("%d %d %d", &a, &b, &c);
    vp[c].push_back(make_pair(a, b));
    mx = max(mx, c);
  }
  for (int i = 1; i <= M; i++) {
    scanf("%d", &a);
    qu[i] = make_pair(a, i);
  }
  sort(qu + 1, qu + M + 1, com);
  int idx = 1;
  long long int sum = 0;
  for (int i = 1; i < SIZE; i++) {
    if (idx > M) break;
    for (int j = 0; j < (int)vp[i].size(); j++) {
      a = vp[i][j].first;
      b = vp[i][j].second;
      int aa = root(a), bb = root(b);
      if (aa != bb) {
        sum -= ((cnt[aa] * (cnt[aa] - 1) / 2) + (cnt[bb] * (cnt[bb] - 1) / 2));
        pn[bb] = aa;
        cnt[aa] += cnt[bb];
        sum += (cnt[aa] * (cnt[aa] - 1) / 2);
      }
    }
    if (i == qu[idx].first) {
      if (qu[idx].first > mx) {
        long long int n = N;
        sum = (n * (n - 1) / 2);
        ans[qu[idx].second] = sum;
        while (qu[idx].first == qu[idx + 1].first) {
          ans[qu[idx].second] = sum;
          idx++;
        }
      } else {
        ans[qu[idx].second] = sum;
        while (qu[idx].first == qu[idx + 1].first) {
          ans[qu[idx].second] = sum;
          idx++;
        }
      }
      idx++;
    }
  }
  for (int i = 1; i <= M; i++) {
    printf("%lld ", ans[i]);
  }
  printf("\n");
  return 0;
}
