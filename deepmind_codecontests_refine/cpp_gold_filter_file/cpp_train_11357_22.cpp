#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
map<string, int> mp;
vector<pair<int, int> > pong;
int B[maxn];
void preprocess(int a, int b) {
  int i = a, j = a - 1;
  B[a] = a - 1;
  while (i < b) {
    while (j >= a && pong[i].first != pong[j].first) j = B[j];
    i++;
    j++;
    B[i] = j;
  }
}
int search(int a, int b, int n) {
  int found = 0;
  int i = 0, j = a;
  while (i < n) {
    while (j >= a && pong[i].first != pong[j].first) j = B[j];
    i++;
    j++;
    if (j == b) {
      found++;
      j = a;
    }
  }
  return found;
}
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (mp.find(x) == mp.end()) {
      mp[x] = ++cnt;
    }
    pong.push_back(pair<int, int>(mp[x], x.size()));
    tot += x.size();
  }
  tot += n - 1;
  int best = 0;
  for (int st = 0; st < n; st++) {
    for (int ed = st + 1; ed < n; ed++) {
      preprocess(st, ed);
      int res = search(st, ed, n);
      if (res == 1) continue;
      int newlen = ed - st;
      int oldlen = 0;
      for (int k = st; k < ed; k++) oldlen += pong[k].second;
      oldlen += ed - st - 1;
      int help = res * (oldlen - newlen);
      best = max(best, help);
    }
  }
  cout << tot - best << endl;
}
