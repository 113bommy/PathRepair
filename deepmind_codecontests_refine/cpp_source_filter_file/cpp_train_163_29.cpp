#include <bits/stdc++.h>
using namespace std;
vector<int> people;
vector<pair<int, int>> keys;
int office, n, k;
bool check(int a) {
  int p = 0, key = 0, cnt = 0;
  while (p < n && key < k) {
    if (abs(people[p] - keys[key].first) + keys[key].second <= a) {
      key++;
      cnt++;
      p++;
    } else
      key++;
  }
  return cnt == n;
}
int main() {
  cin >> n >> k >> office;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    people.push_back(x);
  }
  for (int i = 0, x; i < k; ++i) {
    cin >> x;
    keys.push_back(make_pair(x, abs(x - office)));
  }
  sort(people.begin(), people.end());
  sort(keys.begin(), keys.end());
  int beg = 0, end = 2000000000;
  while (end - beg > 1) {
    int mid = (beg + end) / 2;
    if (check(mid))
      end = mid;
    else
      beg = mid;
  }
  if (check(beg))
    cout << beg;
  else
    cout << end;
  cin >> beg;
  return 0;
}
