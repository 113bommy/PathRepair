#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
pair<long long, long long> t[N];
long long ans[N];
long long ti = 0;
int id = 0;
set<int> s;
int n, p;
void func(int temp, long long time) {
  ti = time + p;
  ans[temp] = ti;
  pair<long long, long long> ele = {ti + 1, -1};
  int index = lower_bound(t, t + n, ele) - t;
  for (int i = id; i < index; i++) {
    if (t[i].second < temp) {
      id = i + 1;
      func(t[i].second, ti);
      break;
    } else {
      s.insert(t[i].second);
      id = i + 1;
    }
  }
}
int main() {
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    t[i].second = i;
    cin >> t[i].first;
  }
  sort(t, t + n);
  while (true) {
    if (!s.size()) {
      if (id == n) {
        break;
      }
      id++;
      func(t[id - 1].second, t[id - 1].first);
    } else {
      int temp = (*s.begin());
      s.erase(temp);
      func(temp, ti);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
