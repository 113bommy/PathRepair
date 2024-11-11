#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5 + 10;
int from[SIZE];
int an[SIZE];
struct data {
  int x, y, id;
  bool operator<(const data& b) const {
    return from[x] < from[b.x] || (from[x] == from[b.x] && y < b.y);
  }
} qq[SIZE];
vector<int> e[SIZE];
vector<pair<int*, int> > record;
void clear_record(int st = 0) {
  for (int i = ((int)(record).size()) - 1; i >= st; i--)
    *record[i].first = record[i].second;
  record.resize(st);
}
struct Union_Find {
  int d[SIZE], num[SIZE];
  void init(int n) {
    for (int i = 0; i < (n); ++i) d[i] = i, num[i] = 1;
  }
  int find(int x) { return (x != d[x]) ? find(d[x]) : x; }
  bool uu(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (num[x] > num[y]) swap(x, y);
    record.push_back(make_pair(&num[y], num[y]));
    num[y] += num[x];
    record.push_back(make_pair(&d[x], d[x]));
    d[x] = y;
    return 1;
  }
} U;
int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  U.init(N);
  int sqN = sqrt(N + 0.1);
  for (int i = 0; i < (N); ++i) {
    from[i] = i / sqN;
  }
  int(m);
  scanf("%d", &m);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  int(Q);
  scanf("%d", &Q);
  for (int i = 0; i < (Q); ++i) {
    scanf("%d%d", &(qq[i].x), &(qq[i].y));
    qq[i].x--;
    qq[i].y--;
    qq[i].id = i;
  }
  sort(qq, qq + Q);
  int lt = -1;
  int dec = 0;
  for (int i = 0; i < (Q); ++i) {
    int x = qq[i].x, y = qq[i].y;
    if (from[x] == from[y]) {
      dec = 0;
      clear_record();
      for (int j = (x); j < (y + 1); ++j) {
        for (int k = 0; k < (((int)(e[j]).size())); ++k) {
          if (e[j][k] < x || e[j][k] > y) continue;
          if (U.uu(j, e[j][k])) {
            dec++;
          }
        }
      }
      lt = -1;
      an[qq[i].id] = y + 1 - x - dec;
      clear_record();
      continue;
    }
    int ed = from[x] * sqN + sqN;
    if (from[x] != lt) {
      dec = 0;
      clear_record();
      for (int j = (ed); j < (y + 1); ++j) {
        for (int k = 0; k < (((int)(e[j]).size())); ++k) {
          if (e[j][k] < ed || e[j][k] > y) continue;
          if (U.uu(j, e[j][k])) {
            dec++;
          }
        }
      }
      lt = from[x];
    } else
      for (int j = (max(qq[i - 1].y + 1, ed)); j < (y + 1); ++j) {
        for (int k = 0; k < (((int)(e[j]).size())); ++k) {
          if (e[j][k] < ed || e[j][k] > y) continue;
          if (U.uu(j, e[j][k])) {
            dec++;
          }
        }
      }
    int dec2 = 0;
    int now_size = ((int)(record).size());
    for (int j = (x); j < (ed); ++j) {
      for (int k = 0; k < (((int)(e[j]).size())); ++k) {
        if (e[j][k] < x || e[j][k] > y) continue;
        if (U.uu(j, e[j][k])) {
          dec2++;
        }
      }
    }
    an[qq[i].id] = y + 1 - x - dec - dec2;
    clear_record(now_size);
  }
  for (int i = 0; i < (Q); ++i) printf("%d\n", an[i]);
  return 0;
}
