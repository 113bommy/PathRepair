#include <bits/stdc++.h>
using namespace std;
struct myData {
  int strength;
  int i, j;
  myData(int str, int x, int y) {
    strength = str;
    i = x;
    j = y;
  }
};
struct cpr {
  bool operator()(myData a, myData b) { return a.strength > b.strength; }
};
set<myData, cpr> mainSet;
int check[801];
int c = 0;
int main() {
  int n, value;
  cin >> n;
  for (int i = 2; i <= 2 * n; ++i) {
    for (int j = 1; j < i; ++j) {
      cin >> value;
      mainSet.insert(myData(value, i, j));
    }
  }
  for (auto it = mainSet.begin(); it != mainSet.end(); ++it) {
    myData p = *it;
    if (!check[p.i] && !check[p.j]) {
      check[p.i] = p.j;
      check[p.j] = p.i;
      c += 1;
    }
    if (c == n) break;
  }
  for (int i = 1; i <= 2 * n; ++i) cout << check[i] << " ";
}
