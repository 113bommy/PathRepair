#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 4;
vector<pair<long long, int> > V1, V2;
int n, m;
int p[maxn];
void kmp() {
  int j = 0;
  for (int i = 1; i < V2.size(); i++) {
    j = p[i];
    while (j && V2[j] != V2[i]) j = p[j];
    if (V2[j] == V2[i]) p[i + 1] = j + 1;
  }
}
void get() {
  int j = 0;
  long long ans = 0;
  for (int i = 0; i < V1.size(); i++) {
    if (j == V2.size() - 1 && V2[j].second == V1[i].second &&
        V2[j].first <= V1[i].first)
      j++;
    else {
      while (j && V2[j] != V1[i]) j = p[j];
      if (j == 0 && V2[j].second == V1[i].second && V2[j].first <= V1[i].first)
        j++;
      else if (V2[j] == V1[i])
        j++;
    }
    if (j == V2.size()) ans++, j = p[j];
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    long long x;
    char y;
    scanf("%lld", &x);
    scanf("%c", &y);
    scanf("%c", &y);
    int z = y - 'a' + 1;
    if (V1.size() && V1.back().second == z)
      V1.back().first += x;
    else
      V1.push_back(make_pair(x, z));
  }
  for (int i = 1; i <= m; i++) {
    long long x;
    char y;
    scanf("%lld", &x);
    scanf("%c", &y);
    scanf("%c", &y);
    int z = y - 'a' + 1;
    if (V2.size() && V2.back().second == z)
      V2.back().first += x;
    else
      V2.push_back(make_pair(x, z));
  }
  if (V2.size() == 1) {
    long long ans = 0;
    for (int i = 0; i < V1.size(); i++)
      if (V1[i].second == V2[0].second && V1[i].first >= V2[0].first)
        ans += (V1[i].first - V2[0].first + 1);
    printf("%lld\n", ans);
    return 0;
  }
  kmp();
  get();
  return 0;
}
