#include <bits/stdc++.h>
using namespace std;
void normalize(vector<pair<pair<int, int>, int> >& in,
               vector<pair<int, pair<int, int> > >& out) {
  if (in.size() == 0) return;
  sort(in.begin(), in.end());
  pair<int, int> start;
  int c = 0;
  for (int i = 0; i < (in.size()); ++i) {
    if (c == 0) {
      start = in[i].first;
    }
    c += in[i].second;
    if (c == 0) {
      out.push_back(make_pair(
          start.first, pair<int, int>(start.second, in[i].first.second)));
    }
  }
}
int result = 0;
int was[200000];
void go(vector<pair<int, pair<int, int> > >& V, int N, int M) {
  int M2 = min(200000, M);
  for (int i = 0; i < (M2); ++i) was[i] = false;
  int left = N;
  for (int i = 0; i < (V.size()); ++i) {
    if (i > 0 && V[i].first != V[i - 1].first) {
      result ^= left;
      --M;
      left = N;
    }
    left -= V[i].second.second - V[i].second.first;
    if (V[i].first < 200000) was[V[i].first] = true;
  }
  if (V.size()) {
    result ^= left;
    --M;
  }
  if (M > 0) {
    result ^= N * (M & 1);
  }
}
pair<int, pair<int, int> > get(vector<pair<int, pair<int, int> > >& V, int cnt,
                               int row) {
  vector<pair<int, int> > tmp;
  for (int i = 0; i < (V.size()); ++i)
    if (V[i].first == row) tmp.push_back(V[i].second);
  tmp.push_back(pair<int, int>(1000000010, 1000000020));
  int A = cnt, B = 0;
  for (int i = 0; i < (tmp.size()); ++i) {
    if (B + A <= tmp[i].first)
      return make_pair(row, pair<int, int>(0, B + A));
    else {
      A -= (tmp[i].first - B);
      B = tmp[i].second;
    }
  }
  throw ":/";
  return make_pair(0, pair<int, int>(0, 0));
}
pair<int, pair<int, int> > get2(vector<pair<int, pair<int, int> > >& V, int N,
                                int M, int cnt) {
  int K = 1 << 30;
  while (!(K & cnt)) K >>= 1;
  int M2 = min(200000, M);
  for (int i = 0; i < (M2); ++i) was[i] = false;
  int left = N;
  for (int i = 0; i < (V.size()); ++i) {
    if (i > 0 && V[i].first != V[i - 1].first) {
      if (left & K) return get(V, left - (cnt ^ left), V[i - 1].first);
      --M;
      left = N;
    }
    left -= V[i].second.second - V[i].second.first;
    if (V[i].first < 200000) was[V[i].first] = true;
  }
  if (V.size()) {
    --M;
    if (left & K) return get(V, left - (cnt ^ left), V[V.size() - 1].first);
  }
  if (M > 0) {
    if (N & K) {
      for (int i = 0; i < (M2); ++i)
        if (!was[i]) return get(V, N - (cnt ^ N), i);
    }
  }
  return make_pair(-1, pair<int, int>(-1, -1));
}
vector<pair<pair<int, int>, int> > H, V;
vector<pair<int, pair<int, int> > > H2, V2;
int main() {
  int N, M, K;
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < (K); ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (y2 < y1) swap(y1, y2);
    if (x2 < x1) swap(x1, x2);
    if (x1 == x2) {
      V.push_back(make_pair(pair<int, int>(x1 - 1, y1), -1));
      V.push_back(make_pair(pair<int, int>(x2 - 1, y2), 1));
    } else {
      H.push_back(make_pair(pair<int, int>(y1 - 1, x1), -1));
      H.push_back(make_pair(pair<int, int>(y2 - 1, x2), 1));
    }
  }
  normalize(H, H2);
  normalize(V, V2);
  result = 0;
  go(H2, N, M - 1);
  go(V2, M, N - 1);
  if (result == 0) {
    printf("SECOND\n");
  } else {
    printf("FIRST\n");
    pair<int, pair<int, int> > res = get2(H2, N, M - 1, result);
    if (res.first >= 0) {
      printf("%d %d %d %d\n", res.second.first, res.first + 1,
             res.second.second, res.first + 1);
    } else {
      res = get2(V2, M, N - 1, result);
      printf("%d %d %d %d\n", res.first + 1, res.second.first, res.first + 1,
             res.second.second);
    }
  }
}
