#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct square {
  int id, cost;
  friend bool operator<(const square& s1, const square& s2) {
    if (s1.cost == s2.cost) {
      return s1.id > s2.id;
    } else
      return s1.cost > s2.cost;
  }
};
square sq[maxn];
int n, k, b;
int main() {
  cin >> n >> k >> b;
  set<int> q;
  for (int i = 0; i < n; i++) {
    scanf("%d", &sq[i].cost);
    sq[i].id = i + 1;
  }
  sort(sq, sq + n - 1);
  int pos = 0;
  for (int i = 0; i < k; i++) {
    b -= sq[i].cost;
    q.insert(sq[i].id);
    if (b < 0) {
      pos = i;
      break;
    } else if (b == 0)
      break;
  }
  if (b >= 0) {
    cout << n << endl;
    return 0;
  } else {
    b += sq[pos].cost;
    for (int i = pos; i < n; i++) {
      if (sq[i].cost > b) {
        q.insert(sq[i].id);
      }
    }
    cout << *q.begin() << endl;
  }
  return 0;
}
