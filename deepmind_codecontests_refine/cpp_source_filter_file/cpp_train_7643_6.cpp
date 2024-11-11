#include <bits/stdc++.h>
using namespace std;
void fm(vector<vector<int> >& mt, vector<int>& from, int n) {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (int j = (0); j < (n); ++j) {
      if (mt[i][j] != 0 && from[j] == 0) {
        from[j] = 1;
        q.push(j);
      }
    }
  }
}
void to_(vector<vector<int> >& mt, vector<int>& to, int n) {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (int j = (0); j < (n); ++j) {
      if (mt[j][i] != 0 && to[j] == 0) {
        to[j] = 1;
        q.push(j);
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  vector<vector<int> > mt(n, vector<int>(n));
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) printf("%d", &mt[i][j]);
  vector<int> from(n, 0);
  from[0] = 1;
  fm(mt, from, n);
  for (int i = (0); i < (n); ++i) {
    if (from[i] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  vector<int> to(n, 0);
  to[0] = 1;
  to_(mt, to, n);
  for (int i = (0); i < (n); ++i) {
    if (to[i] == 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
