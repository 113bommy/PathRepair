#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
deque<int> dq;
vector<pair<int, int>> R;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int M = 0;
  for (auto j = (0); j < (n); ++j) {
    int tmp;
    cin >> tmp;
    dq.push_back(tmp);
    if (tmp > M) {
      M = tmp;
    }
  }
  int cnt = 0;
  while (1) {
    ++cnt;
    int tmp1 = dq.front();
    dq.pop_front();
    int tmp2 = dq.front();
    dq.pop_front();
    R.push_back(make_pair(tmp1, tmp2));
    if (tmp1 < tmp2) swap(tmp1, tmp2);
    dq.push_back(tmp2);
    dq.push_front(tmp1);
    if (tmp1 == M) break;
  }
  for (auto i = (0); i < (m); ++i) {
    ll tmp;
    cin >> tmp;
    if (tmp <= cnt)
      cout << R[tmp - 1].first << ' ' << R[tmp - 1].second << endl;
    else
      cout << M << ' ' << dq[(tmp - cnt - 1) % (n - 1) + 1];
  }
}
