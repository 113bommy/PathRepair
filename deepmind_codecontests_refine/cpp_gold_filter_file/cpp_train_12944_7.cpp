#include <bits/stdc++.h>
using namespace std;
int N, K, cc, len;
char st[1005];
string s[2005];
int a[2005];
vector<int> getdp(int l, int r) {
  if (l == r) {
    vector<int> f;
    f.clear();
    f.push_back(0);
    f.push_back(0);
    return f;
  }
  int minc = 2147483647, mink = 0;
  for (int i = l; i < r; i++)
    if (a[i] < minc) {
      minc = a[i];
      mink = i;
    }
  vector<int> q1 = getdp(l, mink);
  vector<int> q2 = getdp(mink + 1, r);
  vector<int> f;
  f.clear();
  for (int i = 0; i < q1.size() + q2.size() - 1; i++) f.push_back(-2147483647);
  for (int i = 0; i < q1.size(); i++)
    for (int j = 0; j < q2.size(); j++)
      f[i + j] = max(f[i + j], q1[i] + q2[j] + minc * i * j);
  return f;
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%s", st);
    len = strlen(st);
    for (int j = 0; j < len; j++) s[i] += st[j];
  }
  sort(s + 1, s + N + 1);
  for (int i = 1; i < N; i++) {
    cc = 0;
    for (int j = 0; j < min(s[i].size(), s[i + 1].size()); j++)
      if (s[i][j] == s[i + 1][j])
        ++cc;
      else
        break;
    a[i] = cc;
  }
  vector<int> ans = getdp(1, N);
  printf("%d\n", ans[K]);
  return 0;
}
