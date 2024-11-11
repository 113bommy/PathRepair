#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  int n;
  cin >> n;
  set<std::pair<int, int> > bin;
  int x;
  cin >> x;
  bin.insert(make_pair(x, 0));
  for (int i = 1; i < n; i++) {
    cin >> x;
    std::pair<int, int> np = make_pair(x, i);
    auto p = bin.lower_bound(np);
    if (p == bin.begin())
      cout << bin.begin()->first << " ";
    else if (p == bin.end())
      cout << (--p)->first << " ";
    else {
      auto q = p;
      --q;
      if (q->second > p->second)
        cout << q->first << " ";
      else
        cout << q->first << " ";
    }
    bin.insert(np);
  }
}
