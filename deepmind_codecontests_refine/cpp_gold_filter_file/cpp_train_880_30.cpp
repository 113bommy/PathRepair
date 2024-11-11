#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 100;
const int N = 1 << 17;
int st[2 * N];
int ans[MN];
vector<int> addLine[MN];
vector<pair<pair<int, int>, pair<int, int> > > lol[MN];
int getMax(int a, int b) {
  a += N;
  b += N;
  int ma = 0;
  for (; a <= b; a /= 2, b /= 2) {
    if (a & 1) ma = max(ma, st[a++]);
    if (~b & 1) ma = max(ma, st[b--]);
  }
  return ma;
}
void setValue(int a, int v) {
  a += N;
  st[a] = v;
  for (a /= 2; a; a /= 2) {
    st[a] = max(st[a * 2], st[a * 2 + 1]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  vector<pair<int, int> > v(k);
  for (int i = 0; i < k; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  vector<pair<pair<int, int>, pair<int, int> > > v2(q);
  for (int j = 0; j < q; ++j) {
    cin >> v2[j].first.first >> v2[j].first.second >> v2[j].second.first >>
        v2[j].second.second;
  }
  for (int i = 0; i < k; ++i) {
    addLine[v[i].first].push_back(v[i].second);
  }
  for (int j = 0; j < q; ++j) {
    lol[v2[j].first.first].push_back(
        {{v2[j].second.first, j}, {v2[j].first.second, v2[j].second.second}});
  }
  for (int i = 0; i < N; ++i) {
    st[i + N] = 1e9;
  }
  for (int i = N - 1; i; --i) {
    st[i] = max(st[i * 2], st[i * 2 + 1]);
  }
  for (int i = MN - 1; i >= 0; --i) {
    for (int j = 0; j < addLine[i].size(); ++j) {
      setValue(addLine[i][j], i);
    }
    for (int j = 0; j < lol[i].size(); ++j) {
      if (getMax(lol[i][j].second.first, lol[i][j].second.second) <=
          lol[i][j].first.first) {
        ans[lol[i][j].first.second] = 1;
      }
    }
  }
  for (int i = 0; i < MN; ++i) {
    addLine[i].clear();
    lol[i].clear();
  }
  for (int i = 0; i < k; ++i) {
    addLine[v[i].second].push_back(v[i].first);
  }
  for (int j = 0; j < q; ++j) {
    lol[v2[j].first.second].push_back(
        {{v2[j].second.second, j}, {v2[j].first.first, v2[j].second.first}});
  }
  for (int i = 0; i < N; ++i) {
    st[i + N] = 1e9;
  }
  for (int i = N - 1; i; --i) {
    st[i] = max(st[i * 2], st[i * 2 + 1]);
  }
  for (int i = MN - 1; i >= 0; --i) {
    for (int j = 0; j < addLine[i].size(); ++j) {
      setValue(addLine[i][j], i);
    }
    for (int j = 0; j < lol[i].size(); ++j) {
      if (getMax(lol[i][j].second.first, lol[i][j].second.second) <=
          lol[i][j].first.first) {
        ans[lol[i][j].first.second] |= 1;
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    if (ans[i] == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
