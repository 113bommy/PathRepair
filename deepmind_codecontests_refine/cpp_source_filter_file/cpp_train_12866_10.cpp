#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
deque<int> nb[400000];
int ar[400000];
set<pi> lng;
set<int> ins;
int INF = INT_MAX;
int main() {
  int res = 0;
  int n;
  cin >> n;
  ;
  int k;
  cin >> k;
  ;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    ;
    nb[val].push_back(i);
    ar[i] = val;
  }
  int i = 0;
  for (; i < n and ins.size() < k; i++) {
    auto n = nb[ar[i]];
    n.pop_front();
    if (not ins.count(ar[i])) {
      res++;
      ins.insert(ar[i]);
    }
    lng.insert({n.size() ? n.front() : INF, ar[i]});
    ins.insert(ar[i]);
  }
  cerr << "Here" << i << endl;
  for (; i < n; i++) {
    auto n = nb[ar[i]];
    n.pop_front();
    if (not ins.count(ar[i])) {
      res++;
      auto r = *lng.rbegin();
      lng.erase(r);
      ins.erase(r.second);
      ins.insert(ar[i]);
    }
    lng.insert({n.size() ? n.front() : INF, ar[i]});
  }
  cout << res << endl;
}
