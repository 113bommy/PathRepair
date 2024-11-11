#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
map<long long, long long> mp;
long long arr[10000], j, n, m, arr1[10000], mn = 9999999, k = 25;
void bfs(int b) {
  deque<pair<int, int> > v;
  v.push_back(make_pair(b, 0));
  while (!v.empty()) {
    int san = v.front().first;
    int sh = v.front().second;
    v.pop_front();
    k = 25;
    int i = (san / 50) % 475;
    while (k--) {
      i = (i * 96 + 42) % 475;
      if (i + 26 == a) {
        cout << sh << endl;
        return;
      }
    }
    if (mp[san + 100] == 0) {
      v.push_back(make_pair(san + 100, sh + 1));
      mp[san + 100] = 1;
    }
    if (mp[san - 50] == 0 && san - 50 >= c) {
      v.push_front(make_pair(san - 50, sh));
      mp[san - 50] = 1;
    }
  }
}
int main() {
  cin >> a >> b >> c;
  bfs(b);
}
