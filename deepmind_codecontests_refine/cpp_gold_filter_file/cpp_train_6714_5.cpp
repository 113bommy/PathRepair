#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> a, b;
vector<int> ans;
vector<int> ans2;
vector<pair<string, int> > sa, sb;
void solve(int k, vector<int> va, vector<int> vb) {
  int i = 0, j = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    vector<int> fa, fb;
    while (i < va.size() && a[va[i]][k] == c) {
      fa.push_back(va[i++]);
    }
    while (j < vb.size() && b[vb[j]][k] == c) {
      fb.push_back(vb[j++]);
    }
    if (!fa.empty() && !fb.empty()) solve(k + 1, fa, fb);
  }
  vector<int> free;
  for (int x : vb) {
    if (ans2[x] == -1) {
      free.push_back(x);
    }
  }
  int pos = 0;
  for (int x : va) {
    if (ans[x] == -1 && pos < free.size()) {
      ans[x] = free[pos];
      ans2[free[pos]] = x;
      pos++;
    }
  }
}
int main() {
  scanf("%d\n", &n);
  sa = sb = vector<pair<string, int> >(n);
  for (int i = 0; i < (int)(n); i++) {
    getline(cin, sa[i].first);
    sa[i].second = i;
    sa[i].first += char(125);
  }
  for (int i = 0; i < (int)(n); i++) {
    getline(cin, sb[i].first);
    sb[i].second = i;
    sb[i].first += char(126);
  }
  sort(sa.begin(), sa.end());
  sort(sb.begin(), sb.end());
  a = vector<string>(n);
  b = vector<string>(n);
  for (int i = 0; i < (int)(n); i++) {
    a[i] = sa[i].first;
    b[i] = sb[i].first;
  }
  ans = ans2 = vector<int>(n, -1);
  vector<int> p(n);
  for (int i = 0; i < (int)(n); i++) p[i] = i;
  solve(0, p, p);
  int sum = 0;
  for (int i = 0; i < (int)(n); i++) {
    int j = 0;
    while (a[i][j] == b[ans[i]][j]) j++;
    sum += j;
  }
  cout << sum << endl;
  for (int i = 0; i < (int)(n); i++) {
    printf("%d %d\n", sa[i].second + 1, sb[ans[i]].second + 1);
  }
  return 0;
}
