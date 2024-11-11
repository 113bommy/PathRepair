#include <bits/stdc++.h>
using namespace std;
int D, S;
bool vis[500][5001];
int main() {
  cin >> D >> S;
  queue<tuple<int, int, string>> q;
  for (int i = 1; i < 10; i++) {
    q.emplace(i, i, to_string(i));
  }
  while (!q.empty()) {
    int d, s;
    string n;
    tie(d, s, n) = q.front();
    q.pop();
    if (d == 0 && s == S) {
      cout << n << "\n";
      return 0;
    }
    for (int i = 0; i < 10; i++) {
      int dd = (d * 10 + i) % D;
      int ss = s + i;
      if (vis[dd][ss] || ss > S) continue;
      vis[dd][ss] = true;
      q.emplace(dd, ss, n + (char)(i + '0'));
    }
  }
  cout << -1 << "\n";
}
