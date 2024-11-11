#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int M[210][210];
int N;
int Q[] = {-1, 6, 5, 4, 3, 2, 1};
bool query(int a, int b) {
  if (M[a][b] != -1) return M[a][b];
  cout << '?' << ' ' << a << ' ' << b << endl << flush;
  char c;
  cin >> c;
  M[a][b] = (c == '>');
  M[b][a] = 1 - (c == '>');
  return M[a][b];
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  return query(a.second, b.second);
}
int T;
vector<pair<int, int> > V;
int done[200010];
int kill(int tar) {
  int place = 1;
  for (int i = 1; i <= 2 * N; ++i)
    if (i != tar) {
      if (query(i, tar)) place++;
    }
  done[place] = tar;
  return place;
}
vector<int> tmp;
int main() {
  cin >> T;
  while (T--) {
    tmp.clear();
    V.clear();
    cin >> N;
    for (int i = 1; i <= 2 * N; ++i)
      for (int j = 1; j <= 2 * N; ++j) M[i][j] = -1;
    for (int i = 1; i <= 2 * N; ++i) tmp.emplace_back(i);
    while ((int)tmp.size() > 2) {
      V.clear();
      for (int i = 0; i < (int)tmp.size(); i += 2)
        V.emplace_back(tmp[i], tmp[i + 1]);
      for (auto &i : V) {
        if (!query(i.first, i.second)) {
          swap(i.first, i.second);
        }
      }
      sort(V.begin(), V.end(), cmp);
      tmp.clear();
      if ((int)V.size() % 2 == 1) {
        for (int i = 1; i < (int)V.size(); ++i) kill(V[i].second);
        tmp.emplace_back(V[0].first);
        tmp.emplace_back(V[0].second);
        for (int i = 1; i < (int)V.size(); ++i) tmp.emplace_back(V[i].first);
      } else {
        for (int i = 2; i < (int)V.size(); ++i) kill(V[i].second);
        tmp.emplace_back(V[0].first);
        tmp.emplace_back(V[0].second);
        tmp.emplace_back(V[1].first);
        tmp.emplace_back(V[1].second);
        for (int i = 2; i < (int)V.size(); ++i) tmp.emplace_back(V[i].first);
      }
      assert((int)tmp.size() % 2 == 0);
      if ((int)tmp.size() == 4) break;
    }
    if ((int)tmp.size() == 4) {
      int t = tmp[3];
      if (query(tmp[2], tmp[3])) t = tmp[3];
      if (query(t, tmp[1])) t = tmp[3];
      kill(t);
    }
    int t = done[N + 1];
    assert(t);
    for (int i = 1; i <= 2 * N; ++i)
      if (t != i && query(t, i)) {
        for (int j = 1; j <= 2 * N; ++j)
          if (i != j && j != t && query(j, t)) {
            query(i, j);
          }
      }
    cout << '!' << '\n';
  }
}
