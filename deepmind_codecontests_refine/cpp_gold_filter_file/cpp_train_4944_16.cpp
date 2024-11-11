#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005];
int main() {
  int n;
  cin >> n;
  deque<int> p1, p2;
  int c1;
  cin >> c1;
  for (int j = 0; j < c1; j++) {
    int c;
    cin >> c;
    p1.push_back(c);
  }
  int c2;
  cin >> c2;
  for (int j = 0; j < c2; j++) {
    int d;
    cin >> d;
    p2.push_back(d);
  }
  int cnt = 0, flag = 0;
  int winner;
  while (1) {
    if (p1.empty()) {
      winner = 2;
      break;
    } else if (p2.empty()) {
      winner = 1;
      break;
    }
    int x = p1.front();
    p1.pop_front();
    int y = p2.front();
    p2.pop_front();
    if (x > y) {
      p1.push_back(y);
      p1.push_back(x);
    } else {
      p2.push_back(x);
      p2.push_back(y);
    }
    cnt++;
    if (cnt > 10000000) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << cnt << ' ' << winner << endl;
  } else {
    cout << -1 << endl;
  }
}
