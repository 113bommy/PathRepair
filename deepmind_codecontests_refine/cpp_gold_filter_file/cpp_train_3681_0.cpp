#include <bits/stdc++.h>
using namespace std;
void FastIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
stack<pair<int, int> > stk;
string ip;
int length;
int main() {
  FastIO();
  cin >> ip;
  length = ip.length();
  int prev[length + 10], open[length + 10];
  pair<int, int> ppp;
  memset(open, 0, sizeof(open));
  if (ip[0] == '[') open[0]++;
  for (int i = 1; i < length; i++) {
    open[i] = open[i - 1];
    if (ip[i] == '[') open[i]++;
  }
  for (int i = 0; i < length; i++) {
    prev[i] = -1;
    if (ip[i] == '(')
      stk.push(make_pair(1, i));
    else if (ip[i] == '[')
      stk.push(make_pair(2, i));
    else if (ip[i] == ']' && !stk.empty()) {
      ppp = stk.top();
      if (ppp.first != 2) {
        stk.push(make_pair(-1, -1));
      }
      if (ppp.first == 2) {
        stk.pop();
        prev[i] = ppp.second;
      }
    } else if (ip[i] == ')' && !stk.empty()) {
      ppp = stk.top();
      if (ppp.first != 1) {
        stk.push(make_pair(-1, -1));
      }
      if (ppp.first == 1) {
        stk.pop();
        prev[i] = ppp.second;
      }
    }
  }
  string anssubsr;
  int ans = 0, t;
  for (int i = 0; i < length; i++) {
    if (prev[i] != -1) {
      t = prev[i];
      while (prev[t - 1] != -1 && t > 0) {
        t = prev[t - 1];
        if (t <= 0) break;
      }
      prev[i] = t;
    }
  }
  int at, from;
  for (int i = 0; i < length; i++) {
    if (prev[i] != -1) {
      t = prev[i];
      prev[i]--;
      if (prev[i] >= 0) open[i] -= open[prev[i]];
      if (open[i] > ans) {
        ans = open[i];
        from = t;
        at = i;
      }
    }
  }
  if (ans != 0) {
    cout << ans << endl;
    for (int k = from; k <= at; k++) cout << ip[k];
    cout << endl;
  } else
    cout << 0 << endl;
  return 0;
}
