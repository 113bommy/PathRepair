#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  vector<pair<int, int> > g;
  cin >> k;
  if (k % 2 == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (k == 1) {
    cout << "YES" << endl;
    cout << "2 1" << endl;
    cout << "1 2" << endl;
    return 0;
  }
  int group = 2 * (k - 1);
  int halfGroup = group / 2;
  int topA = 2, botA = topA + halfGroup - 1;
  int topB = 2 + halfGroup, botB = topB + halfGroup - 1;
  int offset = 1 + group;
  for (int i = 2; i < 2 + halfGroup; i++) {
    g.push_back(make_pair(1, i));
    g.push_back(make_pair(1 + offset, i + offset));
  }
  g.push_back(make_pair(topA, topB));
  g.push_back(make_pair(topA + offset, topB + offset));
  g.push_back(make_pair(botA, botB));
  g.push_back(make_pair(botA + offset, botB + offset));
  for (int i = topA + 1; i < botA - 1; i++) {
    g.push_back(make_pair(i, i + 1));
    g.push_back(make_pair(i + offset, i + 1 + offset));
  }
  for (int i = topB; i < botB; i++) {
    g.push_back(make_pair(i, i + 1));
    g.push_back(make_pair(i + offset, i + 1 + offset));
  }
  for (int i = topA; i <= botA; i++) {
    for (int j = topB; j <= botB; j++) {
      if (i + halfGroup == j) continue;
      g.push_back(make_pair(i, j));
      g.push_back(make_pair(i + offset, j + offset));
    }
  }
  g.push_back(make_pair(1, 1 + offset));
  int n = group * 2;
  int m = g.size();
  cout << "YES" << endl;
  cout << n << " " << m << endl;
  for (int i = 0; i < g.size(); i++) {
    cout << g[i].first << " " << g[i].second << endl;
  }
}
