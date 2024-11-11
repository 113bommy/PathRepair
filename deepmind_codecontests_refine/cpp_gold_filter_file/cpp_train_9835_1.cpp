#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, st, lt;
  cin >> n >> x;
  deque<pair<int, int>> l;
  for (int i = 0; i < n; i++) {
    cin >> st >> lt;
    l.push_back(make_pair(st, lt));
  }
  int i = 1, c = 0, trav = 1, last, nt;
  while (!l.empty()) {
    nt = l.front().first;
    while (trav <= nt) {
      trav = trav + x;
    }
    trav = trav - x;
    last = l.front().second;
    c = c + (last - trav) + 1;
    trav = last + 1;
    l.pop_front();
  }
  cout << c << endl;
}
