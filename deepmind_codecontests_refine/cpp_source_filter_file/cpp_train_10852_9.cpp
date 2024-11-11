#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
const int MAXQ = 100010;
const double EPS = 1e-10;
const double DINF = 1e30;
const int IINF = ~0U >> 1;
const long long LINF = 1LL << 61;
void debug() { cout << "error_here" << endl; }
int n, s;
priority_queue<pair<int, int> > h;
vector<pair<int, int> > ans;
void printno() {
  puts("No");
  exit(0);
}
void init() {
  scanf("%d%d", &n, &s);
  if (s & 1) printno();
  for (int i = 1, a; i <= n; ++i) {
    scanf("%d", &a);
    h.push(make_pair(a, i));
  }
  while (!h.empty()) {
    pair<int, int> x = h.top();
    h.pop();
    vector<pair<int, int> > load;
    for (int i = 0; i < x.first; ++i) {
      if (h.empty()) printno();
      pair<int, int> y = h.top();
      h.pop();
      if (y.first == 0) printno();
      ans.push_back(make_pair(x.second, y.second));
      y.first--;
      load.push_back(y);
    }
    for (int i = 0; i < (int)load.size(); ++i) h.push(load[i]);
  }
  puts("YES");
  printf("%d\n", ans.size());
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  init();
  return 0;
}
