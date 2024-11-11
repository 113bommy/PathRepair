#include <bits/stdc++.h>
using namespace std;
bool dbg = 0;
int main() {
  int N;
  cin >> N;
  vector<pair<int, pair<int, int> > > a;
  int x;
  int K = 2 * N;
  for (int n = 2; n <= K; ++n) {
    for (int i = 1; i < n; ++i) {
      scanf("%d", &x);
      a.push_back(make_pair(x, make_pair(n, i)));
    }
  }
  sort(a.rbegin(), a.rend());
  int Team[4 * N + 5];
  memset(Team, (int)-1, sizeof(Team));
  ;
  int y;
  for (int n = 0; n < a.size(); ++n) {
    x = a[n].second.first;
    y = a[n].second.second;
    if (dbg) {
      cout << a[n].first << " " << x << " " << y << endl;
    }
    if (Team[x] == -1 && Team[y] == -1) {
      Team[x] = y;
      Team[y] = x;
    }
  }
  for (int n = 1; n <= 2 * N; ++n) {
    cout << Team[n] << " ";
  }
  cout << endl;
  return 0;
}
