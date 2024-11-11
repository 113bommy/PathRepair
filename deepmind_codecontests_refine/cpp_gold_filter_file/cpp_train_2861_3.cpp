#include <bits/stdc++.h>
using namespace std;
ifstream fin("A.in");
ofstream fout("A.out");
int t[100010], v[100010], n, m, T;
string s;
int main() {
  int n;
  cin >> n >> m >> T;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    t[i] = ((s[0] - '0') * 10 + s[1] - '0') * 60 * 60 +
           ((s[3] - '0') * 10 + (s[4] - '0')) * 60 + (s[6] - '0') * 10 + s[7] -
           '0';
  }
  queue<int> q;
  queue<int> Q;
  int cnt = 0;
  int tt = 0;
  int last = 0;
  bool ok = 0;
  for (int i = 1; i <= n; ++i) {
    while (!q.empty() && q.front() < t[i]) {
      int x = Q.front();
      Q.pop();
      q.pop();
      if (Q.empty() || Q.front() != x) {
        --cnt;
      }
    }
    if (cnt == m) {
      Q.push(last);
      q.push(t[i] + T - 1);
      v[i] = last;
    } else {
      ++cnt;
      Q.push(++tt);
      q.push(t[i] + T - 1);
      last = tt;
      v[i] = tt;
      if (cnt == m) ok = 1;
    }
  }
  if (!ok) {
    cout << "No solution";
    return 0;
  }
  cout << tt << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << v[i] << "\n";
  }
}
