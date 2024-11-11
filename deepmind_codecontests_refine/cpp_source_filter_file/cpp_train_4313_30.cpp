#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
int n, arr[MAXN], all[MAXN];
double answer;
set<int> s;
bool cmp(int l, int r) {
  if (arr[l] != arr[r]) return arr[l] > arr[r];
  return l > r;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) all[i] = i;
  sort(all, all + n, cmp);
  s.insert(-1);
  s.insert(n);
  for (int i = 0; i < n; i++) {
    auto ind = s.lower_bound(all[i]);
    double l = 0, r = 0, p = 1;
    auto it = ind;
    int pre = all[i];
    for (int j = 0; j < 50 && ~pre; j++) {
      it--;
      p /= 2;
      l += double(pre - (*it)) * p;
      pre = *it;
    }
    it = ind;
    it--;
    pre = all[i];
    p = 1;
    for (int j = 0; j < 50 && pre != n; j++) {
      it++;
      p /= 2;
      r += double((*it) - pre) * p;
      pre = *it;
    }
    answer += arr[all[i]] * l * r * 2;
    s.insert(all[i]);
  }
  answer /= double(n * n);
  cout << fixed << setprecision(12) << answer << endl;
  cin >> n;
  return 0;
}
