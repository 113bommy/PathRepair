#include <bits/stdc++.h>
using namespace std;
int h, q;
set<pair<long long, long long> > good;
long long d;
bool getdegen(set<pair<long long, long long> >::iterator &j) {
  if (j->first > j->second) {
    j = good.erase(j);
    return 1;
  }
  return 0;
}
void setbad(long long l, long long r) {
  pair<long long, long long> range = make_pair(l, r);
  auto j = good.lower_bound(range);
  if (j != good.begin()) j--;
  while (j != good.end()) {
    if (j->second < l)
      j++;
    else if (j->first > r)
      break;
    else if (j->first <= l && j->second >= r) {
      good.insert(make_pair(r + 1, j->second));
      good.insert(make_pair(j->first, l - 1));
      j = good.erase(j);
      j--;
      if (!getdegen(j)) j++;
      if (!getdegen(j)) j++;
    } else if (j->first >= r && j->second <= r) {
      j = good.erase(j);
    } else if (j->first >= l && j->first <= r) {
      good.insert(make_pair(r + 1, j->second)).second;
      j = good.erase(j);
      j++;
    } else if (j->second <= r && j->second >= l) {
      good.insert(make_pair(j->first, l - 1));
      j = good.erase(j);
    }
  }
}
int main() {
  cin >> h >> q;
  h--;
  d = 1LL << h;
  good.insert(make_pair(0, d - 1));
  while (q--) {
    long long i, l, r, ans;
    cin >> i >> l >> r >> ans;
    while (i <= h) {
      i++;
      l *= 2;
      r = r * 2 + 1;
    }
    l -= d;
    r -= d;
    if (ans == 1) {
      if (l > 0) {
        setbad(0, l - 1);
      }
      if (r < d - 1) {
        setbad(r + 1, d - 1);
      }
    } else {
      setbad(l, r);
    }
  }
  if (good.size() == 0) {
    cout << "Game cheated!\n";
  } else if (good.size() > 1 ||
             (good.size() == 1 && good.begin()->first < good.begin()->second)) {
    cout << "Data not sufficient!\n";
  } else {
    cout << good.begin()->first + d << "\n";
  }
  return 0;
}
