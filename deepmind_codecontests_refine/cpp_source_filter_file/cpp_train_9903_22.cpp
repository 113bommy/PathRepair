#include <bits/stdc++.h>
using namespace std;
struct empl {
  int job;
  int time;
  empl(int job = 0, int time = 0) : job(job), time(time) {}
};
bool comp(empl a, empl b) {
  return (a.job < b.job) || (a.job == b.job && a.time > b.time);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie();
  int n, k;
  cin >> n >> k;
  vector<empl> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].job;
  }
  for (int i = 0; i < n; ++i) {
    cin >> v[i].time;
  }
  sort(v.begin(), v.end(), comp);
  vector<int> times;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i].job == v[i - 1].job) {
      times.push_back(v[i].time);
      v.erase(v.begin() + i);
      --i;
    }
  }
  sort(times.begin(), times.end());
  int counter = k - v.size();
  int ans = 0;
  for (int i = 0; i < counter; ++i) {
    ans += times[i];
  }
  cout << ans;
  return 0;
}
