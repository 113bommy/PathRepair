#include <bits/stdc++.h>
using namespace std;
long long a[33][4];
int n;
long long bar;
map<pair<pair<long long, long long>, long long>, long long> m;
map<pair<pair<long long, long long>, long long>, long long> m2;
void go1(int step, long long sa, long long sb, long long sc, long long msk) {
  if (bar == step) {
    m[make_pair(make_pair(sa - sb, sa - sc), sb - sc)] = msk;
    m2[make_pair(make_pair(sa - sb, sa - sc), sb - sc)] = sa;
    return;
  }
  go1(step + 1, sa, sb + a[step][1], sc + a[step][2], msk * 3);
  go1(step + 1, sa + a[step][0], sb, sc + a[step][2], msk * 3 + 1);
  go1(step + 1, sa + a[step][0], sb + a[step][1], sc, msk * 3 + 2);
}
long long ans1 = 0, ans2 = 0, val = -1e15;
void go2(int step, long long sa, long long sb, long long sc, long long msk) {
  if (n + 1 == step) {
    if (bar == 1) {
      if (sa == sb && sb == sc) {
        if (sa > val) {
          ans2 = msk;
          val = sa;
        }
      }
    }
    if (m.count(make_pair(make_pair(sb - sa, sc - sa), sc - sb))) {
      int its = m2[make_pair(make_pair(sb - sa, sc - sa), sc - sb)];
      if (its + sa > val) {
        val = its + sa;
        ans1 = m[make_pair(make_pair(sb - sa, sc - sa), sc - sb)];
        ans2 = msk;
      }
    }
    return;
  }
  go2(step + 1, sa, sb + a[step][1], sc + a[step][2], msk * 3);
  go2(step + 1, sa + a[step][0], sb, sc + a[step][2], msk * 3 + 1);
  go2(step + 1, sa + a[step][0], sb + a[step][1], sc, msk * 3 + 2);
}
string getstre(int a) {
  if (a == 0)
    return "MW\n";
  else if (a == 1)
    return "LW\n";
  else
    return "LM\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  bar = (n + 1) / 2;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> a[i][j];
    }
  }
  go1(1, 0, 0, 0, 0);
  go2(bar, 0, 0, 0, 0);
  if (val == -1e15) {
    cout << "Impossible\n";
    return 0;
  }
  vector<int> a1, a2, a3;
  for (int i = 1; i < bar; ++i) {
    a1.push_back(ans1 % 3);
    ans1 /= 3;
  }
  for (int i = bar; i <= n; ++i) {
    a2.push_back(ans2 % 3);
    ans2 /= 3;
  }
  reverse((a1).begin(), (a1).end());
  reverse((a2).begin(), (a2).end());
  for (int i = 0; i < a1.size(); ++i) {
    cout << getstre(a1[i]);
  }
  for (int i = 0; i < a2.size(); ++i) {
    cout << getstre(a2[i]);
  }
  return 0;
}
