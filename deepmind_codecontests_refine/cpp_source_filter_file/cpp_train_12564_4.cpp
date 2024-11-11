#include <bits/stdc++.h>
using namespace std;
long long poww(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
long long n, k, road[5][200];
vector<pair<long long, pair<long long, long long> > > v;
void calc() {
  long long cnt = 0, j;
  while (cnt < k) {
    for (j = n; j >= 1; j--) {
      if (road[2][j] == 0) continue;
      if (road[2][j] == road[1][j]) {
        road[2][j] = 0;
        cnt++;
        v.push_back(make_pair(road[1][j], make_pair(1, j)));
      } else if (j == 1) {
        if (road[3][j] == 0) {
          road[3][j] = road[2][j];
          road[2][j] = 0;
          v.push_back(make_pair(road[3][j], make_pair(3, j)));
        }
      } else if (road[2][j - 1] == 0) {
        road[2][j - 1] = road[2][j];
        road[2][j - 1] = 0;
        v.push_back(make_pair(road[2][j - 1], make_pair(2, j - 1)));
      }
    }
    for (j = 1; j <= n; j++) {
      if (road[3][j] == 0) continue;
      if (road[3][j] == road[4][j]) {
        road[3][j] = 0;
        cnt++;
        v.push_back(make_pair(road[4][j], make_pair(4, j)));
      } else if (j == n) {
        if (road[2][j] == 0) {
          road[2][j] = road[3][j];
          road[3][j] = 0;
          v.push_back(make_pair(road[2][j], make_pair(2, j)));
        }
      } else if (road[3][j + 1] == 0) {
        road[3][j + 1] = road[3][j];
        road[3][j] = 0;
        v.push_back(make_pair(road[3][j + 1], make_pair(3, j + 1)));
      }
    }
    if (v.size() > 20000 || v.size() == 0) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << v.size() << '\n';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second
         << '\n';
  }
}
int main() {
  long long i, j;
  cin >> n >> k;
  for (i = 1; i <= 4; i++)
    for (j = 1; j <= n; j++) cin >> road[i][j];
  calc();
  return 0;
}
