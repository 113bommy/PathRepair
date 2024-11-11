#include <bits/stdc++.h>
using namespace std;
struct W {
  int ind;
  string st;
  bool operator<(const W &a) const { return st > a.st; }
};
priority_queue<W> q;
string str;
int main() {
  int k, n;
  long long t;
  cin >> str;
  cin >> k;
  n = str.size();
  t = n * (n + 1) / 2;
  if (t < k) {
    cout << "No such line.";
    return 0;
  }
  W now;
  for (int i = 0; i < n; i++) {
    now.st = str[i];
    now.ind = i + 1;
    q.push(now);
  }
  while (--k) {
    now = q.top();
    q.pop();
    if (now.ind < n) {
      now.st += str[now.ind++];
      q.push(now);
    }
  }
  now = q.top();
  cout << now.st;
  return 0;
}
