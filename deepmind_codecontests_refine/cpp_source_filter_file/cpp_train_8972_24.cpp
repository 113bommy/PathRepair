#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll query1(int i, int j, int k) {
  cout << "1 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  ll s;
  cin >> s;
  return s;
}
int query2(int i, int j, int k) {
  cout << "2 " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
  int s;
  cin >> s;
  return s;
}
const ll INF = 5e18;
int main() {
  int n;
  cin >> n;
  vector<bool> dir(n);
  for (int i = 2; i < n; i++) {
    dir[i] = query2(0, 1, i) > 0;
  }
  vector<ll> S(n);
  for (int i = 2; i < n; i++) {
    S[i] = query1(0, 1, i);
  }
  int id1 = 0, id2 = 1, ma1 = 0, ma2 = 0;
  for (int i = 2; i < n; i++) {
    if (dir[i]) {
      if (ma1 < S[i]) {
        ma1 = S[i];
        id1 = i;
      }
    } else {
      if (ma2 < S[i]) {
        ma2 = S[i];
        id2 = i;
      }
    }
  }
  vector<int> flag(n);
  for (int i = 2; i < n; i++)
    if (i != id1 && i != id2) {
      flag[i] = query2(id1, id2, i) > 0;
    }
  vector<tuple<int, ll, int>> ids;
  ids.emplace_back(0, 0, 0);
  if (id2 != 1) ids.emplace_back(1, -INF, id2);
  ids.emplace_back(2, 0, 1);
  if (id1 != 0) ids.emplace_back(3, -INF, id1);
  for (int i = 2; i < n; i++)
    if (i != id1 && i != id2) {
      if (dir[i]) {
        if (flag[i]) {
          ids.emplace_back(2, S[i], i);
        } else {
          ids.emplace_back(3, -S[i], i);
        }
      } else {
        if (flag[i]) {
          ids.emplace_back(1, -S[i], i);
        } else {
          ids.emplace_back(0, S[i], i);
        }
      }
    }
  sort(ids.begin(), ids.end());
  cout << 0;
  for (int i = 0; i < n; i++) {
    cout << ' ' << get<2>(ids[i]) + 1;
  }
  cout << endl;
  return 0;
}
