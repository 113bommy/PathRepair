#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  int c, p, id;
};
int compare(node t1, node t2) { return t1.p < t2.p; }
int compare2(pair<int, int> t1, pair<int, int> t2) {
  return t1.first < t2.first;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, c, p, k, r;
  cin >> n;
  vector<node> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> c >> p;
    input[i] = {c, p, i + 1};
  }
  sort(input.begin(), input.end(), compare);
  cin >> k;
  vector<pair<int, int> > T(k);
  for (int i = 0; i < k; ++i) {
    cin >> r;
    T[i] = {r, i + 1};
  }
  sort(T.begin(), T.end(), compare2);
  vector<pair<int, int> > out;
  int total = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < T.size(); ++j) {
      if (T[j].first >= input[i].c) {
        out.push_back({input[i].id, T[j].second});
        total += input[i].p;
        T.erase(T.begin() + j);
        break;
      }
    }
  }
  cout << out.size() << ' ' << total << '\n';
  for (auto it : out) cout << it.first << ' ' << it.second << '\n';
  return 0;
}
