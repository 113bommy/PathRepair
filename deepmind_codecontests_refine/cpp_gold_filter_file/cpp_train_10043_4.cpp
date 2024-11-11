#include <bits/stdc++.h>
using namespace std;
const int N = 125009;
const int P = 1000000009;
set<pair<int, int> > S;
pair<int, int> T;
vector<pair<int, int> > v;
int a[N], b[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &a[i], &b[i]), S.insert(make_pair(a[i], i));
  while (S.size()) {
    T = *S.begin();
    S.erase(T);
    int I = T.second;
    if (a[I] == 1) {
      v.push_back(make_pair(I, b[I]));
      b[b[I]] ^= I;
      S.erase(make_pair(a[b[I]], b[I]));
      a[b[I]]--;
      S.insert(make_pair(a[b[I]], b[I]));
    }
  }
  printf("%d\n", (int)v.size());
  for (int i = 0; i < v.size(); i++) printf("%d %d\n", v[i].first, v[i].second);
  return 0;
}
