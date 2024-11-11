#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<pair<string, int>> ins;
  for (int i = 0; i < n; ++i) {
    string t1;
    int t2;
    cin >> t1 >> t2;
    ins.push_back({t1, t2});
  }
  map<string, int> tot;
  int m = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (tot.find(ins[i].first) == tot.end()) {
      tot.insert({ins[i].first, ins[i].second});
    } else {
      string t1 = ins[i].first;
      tot[t1] += ins[i].second;
    }
  }
  auto it = tot.begin();
  for (; it != tot.end(); it++) {
    m = max(m, it->second);
  }
  set<string> ms;
  for (pair<string, int> e : tot) {
    if (e.second == m) ms.insert(e.first);
  }
  map<string, int> count;
  for (int i = 0; i < n; ++i) {
    if (count.find(ins[i].first) == count.end()) {
      count.insert({ins[i].first, ins[i].second});
    } else {
      count[ins[i].first] += ins[i].second;
    }
    if (count[ins[i].first] >= m && (ms.find(ins[i].first) != ms.end())) {
      cout << ins[i].first << endl;
      return 0;
    }
  }
}
