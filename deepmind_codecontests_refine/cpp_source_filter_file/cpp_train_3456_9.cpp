#include <bits/stdc++.h>
using namespace std;
int Nr[200005], Prv[200005];
vector<int> Val[200005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
      Nr[i] = Prv[i] = 0;
      Val[i].clear();
    }
    for (int i = 1; i <= n; i++) {
      int x, y;
      cin >> x >> y;
      Nr[x]++;
      Val[x].push_back(y);
    }
    Prv[0] = Nr[0];
    for (int i = 1; i <= n; i++) Prv[i] = Nr[i] + Prv[i - 1];
    int del = 0;
    int rez = 0;
    priority_queue<int> Q;
    for (int i = n; i >= 1; i--) {
      if (Nr[i] == 0) continue;
      for (auto x : Val[i]) Q.push(-x);
      if (i <= Prv[i - 1] + del) continue;
      while (Prv[i - 1] + del < i) {
        rez += (-Q.top());
        Q.pop();
        del++;
      }
    }
    cout << rez << "\n";
  }
  return 0;
}
