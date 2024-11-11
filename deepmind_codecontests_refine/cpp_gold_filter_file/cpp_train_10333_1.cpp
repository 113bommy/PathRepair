#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
stack<int> can;
bool hold[MAXN];
int main() {
  int n;
  cin >> n;
  if (n <= 3) {
    cout << 0 << endl;
    return 0;
  }
  int a = 1;
  int b = 1;
  while (a * b < n) {
    a++;
    if (a > b) {
      swap(a, b);
    }
  }
  for (int i = 0; i < n; i++) {
    if (i % b != 0) {
      can.push(i);
    }
  }
  while ((int)can.size() >= b) {
    cout << b;
    for (int i = 0; i < b; i++) {
      int y = can.top();
      cout << " " << y + 1;
      hold[y] = true;
      can.pop();
    }
    cout << endl;
    cout.flush();
    int x;
    cin >> x;
    for (int i = 0; i < b; i++) {
      int y = (x - 1 + i) % n;
      if (hold[y]) {
        hold[y] = false;
        can.push(y);
      }
    }
  }
  cout << 0 << endl;
}
