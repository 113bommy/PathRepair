#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 7;
int n, m, k, s;
int a[MAX], b[MAX];
vector<pair<int, int> > v, ans;
bool check(int m) {
  ans.clear();
  pair<int, int> dollar = make_pair(INT_MAX, INT_MAX);
  pair<int, int> pound = make_pair(INT_MAX, INT_MAX);
  for (int i = 1; i <= m; i++)
    dollar = min(dollar, make_pair(a[i], i)),
    pound = min(pound, make_pair(b[i], i));
  vector<pair<long long, int> > temp;
  int o = 0;
  for (auto j : v) {
    o++;
    if (j.first == 1)
      temp.push_back(
          make_pair((long long)j.second * (long long)dollar.first, -o));
    else
      temp.push_back(
          make_pair((long long)j.second * (long long)pound.first, o));
  }
  sort(temp.begin(), temp.end());
  long long sum = 0;
  for (auto j : temp) {
    sum += j.first;
    if (sum <= s) {
      if (j.second > 0)
        ans.push_back(make_pair(j.second, pound.second));
      else
        ans.push_back(make_pair(-j.second, dollar.second));
    } else
      break;
    if (ans.size() >= k) break;
  }
  return ans.size() >= k;
}
int func() {
  int beg = 1, last = n;
  int mid;
  while (true) {
    mid = (beg + last) / 2;
    if (beg == last) {
      if (check(beg)) return beg;
      return -1;
    }
    if (beg + 1 == last) {
      if (check(beg)) return beg;
      if (check(last)) return last;
      return -1;
    }
    if (check(mid))
      last = mid;
    else
      beg = mid + 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  while (m--) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  int val = func();
  cout << val << endl;
  if (val != -1)
    for (auto j : ans) cout << j.first << " " << j.second << endl;
  return 0;
}
