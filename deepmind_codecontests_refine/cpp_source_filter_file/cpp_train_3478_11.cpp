#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > V;
vector<string> RES[100010];
int n;
int main() {
  cin >> n;
  int lastzero = -1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0) {
      sort(V.begin(), V.end());
      if (V.size() == 1) {
        RES[V[0].second].push_back("pushStack");
        RES[i].push_back("popStack");
      } else if (V.size() == 2) {
        RES[V[0].second].push_back("pushStack");
        RES[V[1].second].push_back("pushQueue");
        RES[i].push_back("popStack");
        RES[i].push_back("popQueue");
      } else if (V.size() >= 3) {
        RES[V[0].second].push_back("pushStack");
        RES[V[1].second].push_back("pushQueue");
        RES[V[2].second].push_back("pushFront");
        for (int j = 3; j < V.size(); j++) {
          RES[V[j].second].push_back("pushBack");
        }
        RES[i].push_back("popStack");
        RES[i].push_back("popQueue");
        RES[i].push_back("popFront");
      }
      V.clear();
      lastzero = i;
    } else {
      V.push_back({-x, i});
    }
  }
  if (lastzero != n) {
    for (int i = 0; i < V.size(); i++) {
      RES[V[i].second].push_back("pushBack");
    }
  }
  for (int i = 0; i < n; i++) {
    if (RES[i].size() == 0 or RES[i][0].substr(0, 3) == "pop") {
      cout << RES[i].size() << ' ';
      for (int j = 0; j < RES[i].size(); j++) {
        cout << ' ' << RES[i][j];
      }
    } else {
      cout << RES[i][0];
    }
    cout << '\n';
  }
  return 0;
}
