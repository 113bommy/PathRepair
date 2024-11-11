#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int mod = 1000000007;
const double pi = (double)22 / 7;
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> wight(n);
  for (int i = 0; i < n; cin >> wight[i++])
    ;
  vector<int> book(m);
  for (int i = 0; i < m; cin >> book[i++])
    ;
  map<int, bool> u;
  vector<int> list;
  for (int i = 0; i < m; i++) {
    if (!u[book[i]]) {
      u[book[i]] = 1;
      list.push_back(book[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int j = 0;
    while (list[j] != book[i]) {
      ans += wight[list[j] - 1];
      j++;
      if (list[j] == book[i]) {
        list.erase(list.begin() + j);
        list.insert(list.begin(), book[i]);
        break;
      }
    }
  }
  cout << ans;
}
