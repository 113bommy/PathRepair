#include <bits/stdc++.h>
using namespace std;
queue<int> get_intput() {
  int k, tmp;
  cin >> k;
  queue<int> x;
  for (int i = 0; i < k; i++) {
    cin >> tmp;
    x.push(tmp);
  }
  return x;
}
int main() {
  int n, k, x, pl = 0;
  cin >> n;
  queue<int> q1, q2;
  q1 = get_intput();
  q2 = get_intput();
  for (int i = 0; i < 100; i++) {
    int a = q1.front(), b = q2.front();
    q1.pop(), q2.pop();
    if (a > b) {
      q1.push(b);
      q1.push(a);
    } else {
      q2.push(a);
      q2.push(b);
    }
    if (q1.empty())
      return cout << i + 1 << "  2", 0;
    else if (q2.empty())
      return cout << i + 1 << "  1", 0;
  }
  cout << -1;
  return 0;
}
