#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
int n, m, t;
vector<int> q;
bool read() {
  if (scanf("%d %d %d", &n, &m, &t) != 3) return false;
  q.clear();
  for (int i = 0; i < int(n); ++i) {
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int timestamp = (hh * 60 + mm) * 60 + ss;
    q.push_back(timestamp);
  }
  return true;
}
void solve() {
  vector<int> ans;
  int p = 0, k = 0;
  bool intersects = false;
  queue<int> tq;
  queue<int> idq;
  map<int, int> ids;
  for (int i = 0; i < 24 * 60 * 60; i++) {
    while (p < (int)(q).size() && q[p] <= i) {
      if ((int)(ids).size() < m) k++;
      ids[k]++;
      idq.push(k);
      tq.push(q[p]);
      p++;
    }
    if ((int)(ids).size() >= m) intersects = true;
    while (!tq.empty() && tq.front() + t == i) {
      int tid = idq.front();
      ans.push_back(tid);
      tq.pop();
      idq.pop();
      ids[tid]--;
      if (ids[tid] <= 0) ids.erase(tid);
    }
  }
  if (!intersects) {
    puts("No solution");
  } else {
    printf("%d\n", k);
    for (int i = 0; i < int((int)(ans).size()); ++i) printf("%d\n", ans[i]);
  }
  puts("");
}
int main() {
  while (read()) solve();
  return 0;
}
