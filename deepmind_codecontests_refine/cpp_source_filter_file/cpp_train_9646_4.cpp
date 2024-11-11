#include <bits/stdc++.h>
using namespace std;
int main() {
  string in;
  cin >> in;
  set<long long> squares;
  for (long long i = 1; i * i < 1e9 + 1; ++i) squares.insert(i * i);
  queue<string> q;
  q.push(in);
  while (!q.empty()) {
    string c = q.front();
    q.pop();
    long long val = stoi(c);
    if (squares.count(val)) {
      cout << (in.size() - c.size()) << endl;
      return 0;
    }
    for (int i = 0; i < c.size(); ++i) {
      string n = c;
      n.erase(i, 1);
      if (n.size() == 0) continue;
      if (n[0] == '0') continue;
      q.push(n);
    }
  }
  cout << -1 << endl;
}
