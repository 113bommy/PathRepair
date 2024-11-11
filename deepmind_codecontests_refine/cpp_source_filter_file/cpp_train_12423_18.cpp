#include <bits/stdc++.h>
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
bool valid(int r, int c, int x, int y) {
  if (x >= 1 && x <= r && y >= 1 && y <= c) return 1;
  return 0;
}
using namespace std;
priority_queue<int> pq;
int main() {
  string s, a;
  cin >> a >> s;
  int p = a.length();
  int q = s.length();
  for (int i = 0; i < q; i++) {
    int x = (int)s[i] - 48;
    pq.push(x);
  }
  int flag = 0;
  int i;
  for (i = 0; i < p; i++) {
    int x = (int)a[i] - 48;
    if (pq.size() == 0) {
      flag = 1;
      break;
    }
    if (x < pq.top()) {
      cout << pq.top();
      pq.pop();
    } else
      cout << a[i];
  }
  if (flag) {
    for (int j = i; j < p; j++) cout << a[i];
  }
  cout << endl;
  return 0;
}
