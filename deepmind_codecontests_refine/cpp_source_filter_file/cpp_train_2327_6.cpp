#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  map<long long, int> m;
  int act = 0;
  vector<pair<int, int> > in;
  for (int(i) = 0; (i) < (N); ++(i)) {
    long long a, b;
    cin >> a >> b;
    if (!m.count(a)) {
      m[a] = act;
      act++;
    }
    if (!m.count(b)) {
      m[b] = act;
      act++;
    }
    in.push_back(make_pair(m[a], m[b]));
  }
  vector<int> front(act, 0);
  vector<int> back(act, 0);
  for (int(i) = 0; (i) < (N); ++(i)) {
    front[in[i].first]++;
    if (in[i].first != in[i].second) back[in[i].second]++;
  }
  int mn = INT_MAX;
  for (int(i) = 0; (i) < (act); ++(i)) {
    if (front[i] + back[i] >= ((N + 1) / 2)) {
      mn = min(mn, ((N + 1) / 2) - front[i]);
    }
  }
  if (mn == INT_MAX)
    cout << "-1" << endl;
  else
    cout << mn << endl;
  return 0;
}
