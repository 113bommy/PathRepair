#include <bits/stdc++.h>
using namespace std;
vector<int> max_vec, min_vec;
vector<int>::iterator it;
bool own_pos[100007];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, prev, t, test, max_, min_, n, tot_own = 0;
  cin >> test;
  for (int tt = 0; tt < test; tt++) {
    cin >> n;
    max_ = -5;
    min_ = INT_MAX;
    cin >> prev;
    n--;
    min_ = min(min_, prev);
    max_ = max(max_, prev);
    own_pos[tt] = false;
    while (n--) {
      cin >> x;
      if (prev < x) own_pos[tt] = true;
      prev = x;
      max_ = max(max_, prev);
      min_ = min(min_, prev);
    }
    if (own_pos[tt])
      tot_own++;
    else
      max_vec.push_back(max_);
    min_vec.push_back(min_);
  }
  int dist = 0, cnt = 0;
  sort(max_vec.begin(), max_vec.end());
  for (int tt = 0; tt < test; tt++) {
    if (own_pos[tt])
      cnt += test;
    else {
      if (min_vec[tt] < max_vec[max_vec.size() - 1]) {
        it = upper_bound(max_vec.begin(), max_vec.end(), min_vec[tt]);
        dist = it - max_vec.begin();
        dist = max_vec.size() - dist;
        cnt += dist;
      }
      cnt += tot_own;
    }
  }
  cout << cnt << endl;
  return 0;
}
