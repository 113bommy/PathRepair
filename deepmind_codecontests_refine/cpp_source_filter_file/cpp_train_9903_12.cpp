#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
bool visit[maxn];
bool check[maxn];
struct data {
  int job, time;
};
bool cmp(data a, data b) {
  if (a.job == b.job) {
    return a.time > b.time;
  }
  return a.job < b.job;
}
vector<int> v;
int main() {
  int n, k;
  cin >> n >> k;
  data ara[n];
  int extra = k;
  for (int i = 0; i < n; i++) {
    cin >> ara[i].job;
    if (!check[ara[i].job]) {
      extra--;
      check[ara[i].job] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> ara[i].time;
  }
  sort(ara, ara + n, cmp);
  for (int i = 0; i < n; i++) {
    if (!visit[ara[i].job]) {
      visit[ara[i].job] = true;
    } else {
      v.push_back(ara[i].time);
    }
  }
  sort(v.begin(), v.end());
  int ans = 0;
  for (int i = 0; i < extra; i++) {
    ans += v[i];
  }
  cout << ans << endl;
  return 0;
}
