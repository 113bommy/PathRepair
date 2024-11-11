#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
vector<vector<int> > arr[6];
int n, a[N], vis[N];
void Allocate(vector<int>& v) {
  for (int i = 1, j = i; i < (int)(v).size(); i = j) {
    vector<int> nv;
    nv.push_back(v[0]);
    for (; j < (int)(v).size() && j - i < 4; ++j) nv.push_back(v[j]);
    arr[(int)(nv).size()].push_back(nv);
  }
}
void Trans() {
  vector<int> v = arr[3].back();
  arr[3].pop_back();
  vector<int> nv;
  nv.push_back(v[0]);
  nv.push_back(v[1]);
  arr[2].push_back(nv);
  nv.clear();
  nv.push_back(v[1]);
  nv.push_back(v[2]);
  arr[2].push_back(nv);
}
vector<int> f, g;
void put(vector<int>& v) {
  for (int i = 0; i < ((int)(v).size()); ++i)
    f.push_back(v[i]), g.push_back(v[(i + 1) % (int)(v).size()]);
}
void out() {
  printf("%d\n", (int)(f).size());
  for (int i = 0; i < ((int)(f).size()); ++i)
    printf("%d%c", f[i], " \n"[i + 1 == (int)(f).size()]);
  for (int i = 0; i < ((int)(g).size()); ++i)
    printf("%d%c", g[i], " \n"[i + 1 == (int)(g).size()]);
  f.clear();
  g.clear();
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < (n + 1); ++i) scanf("%d", a + i);
  for (int i = 1; i < (n + 1); ++i)
    if (!vis[i]) {
      vector<int> v;
      for (int j = i; !vis[j]; j = a[j]) vis[j] = true, v.push_back(j);
      Allocate(v);
    }
  while ((int)(arr[3]).size() - (int)(arr[2]).size() > 2) Trans();
  int j = 0,
      ans = max(0, ((int)(arr[2]).size() - (int)(arr[3]).size() + 1) / 2) +
            (int)(arr[3]).size() + (int)(arr[4]).size() + (int)(arr[5]).size();
  printf("%d\n", ans);
  for (int i = 0; i < ((int)(arr[5]).size()); ++i) put(arr[5][i]), out();
  for (int i = 0; i < ((int)(arr[4]).size()); ++i) put(arr[4][i]), out();
  for (int i = 0; i < ((int)(arr[3]).size()); ++i) {
    put(arr[3][i]);
    if (j < (int)(arr[2]).size()) put(arr[2][j++]);
    out();
  }
  for (; j < (int)(arr[2]).size();) {
    put(arr[2][j++]);
    if (j < (int)(arr[2]).size()) put(arr[2][j++]);
    out();
  }
  return 0;
}
