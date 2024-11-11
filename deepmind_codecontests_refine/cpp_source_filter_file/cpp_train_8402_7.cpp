#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200005;
int n, w[maxn], vis[maxn];
char s[maxn];
pair<long long, int> a[maxn];
vector<pair<long long, int> > e;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    pair<long long, int> p;
    p.first = x;
    p.second = i + 1;
    e.push_back(p);
  }
  scanf("%s", s);
  sort(e.begin(), e.end());
  priority_queue<pair<long long, int> > q;
  memset(vis, 0, sizeof(vis));
  int cnt = 0;
  for (int i = 0; i < n * 2; i++) {
    if (s[i] == '0') {
      q.push(e[cnt]);
      cout << e[cnt].second << " ";
      cnt++;
    } else {
      cout << q.top().second << " ";
      q.pop();
    }
  }
  return 0;
}
