#include <bits/stdc++.h>
using namespace std;
struct cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first <= b.first && a.second <= b.second;
  }
};
int main() {
  int n;
  cin >> n;
  set<pair<int, int>, cmp> spii;
  vector<set<pair<int, int>, cmp> > V(2 * 111111, spii);
  for (int i = 0; i < n; ++i) {
    int first, second;
    cin >> first >> second;
    V[second - first + 111111].insert(make_pair(first, second));
  }
  vector<pair<int, int> > ANS;
  pair<int, int> last = make_pair(-1, -1);
  for (int i = 0; i < n; ++i) {
    int w;
    cin >> w;
    if (V[w + 111111].empty()) {
      cout << "NO" << endl;
      return 0;
    }
    pair<int, int> next = *V[w + 111111].begin();
    if (next.first < last.first && next.second < last.second) {
      cout << "NO" << endl;
      return 0;
    }
    last = next;
    ANS.push_back(next);
    V[w + 111111].erase(V[w + 111111].begin());
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ANS[i].first << " " << ANS[i].second << endl;
  }
  return 0;
}
