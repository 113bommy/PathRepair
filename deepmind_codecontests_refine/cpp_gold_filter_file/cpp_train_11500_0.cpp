#include <bits/stdc++.h>
using namespace std;
vector<long long> a[10];
long long dis(long long x, long long y) {
  long long ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += (a[x][i] - a[y][i]) * (a[x][i] - a[y][i]);
  }
  return ans;
}
void solve(long long now, set<long long> s) {
  if (s.size() > 3) return;
  if (now == 9) {
    if (s.size() == 3) {
      cout << "YES" << endl;
      for (int i = 1; i <= 8; i++) {
        for (auto j : a[i]) {
          cout << j << " ";
        }
        cout << endl;
      }
      exit(0);
    }
    return;
  }
  set<long long> p;
  do {
    p = s;
    for (int i = now - 1; i >= 1; i--) {
      p.insert(dis(i, now));
    }
    solve(now + 1, p);
  } while (next_permutation(a[now].begin(), a[now].end()));
}
int main() {
  for (int i = 1; i <= 8; i++) {
    for (int j = 0; j < 3; j++) {
      long long x;
      cin >> x;
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }
  set<long long> s;
  solve(1, s);
  cout << "NO" << endl;
}
