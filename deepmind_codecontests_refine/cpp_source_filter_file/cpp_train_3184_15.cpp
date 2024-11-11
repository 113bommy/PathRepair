#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int ts, tf, t, n, x;
  map<long long int, long long int> mp;
  cin >> ts >> tf >> t;
  cin >> n;
  long long int tmp = ts;
  while (n--) {
    cin >> x;
    if (tmp + t > tf) continue;
    mp.insert({max(tmp, x), x});
    tmp = max(tmp, x) + t;
  }
  long long int mnt = ts, mn = 1e15;
  auto itr = mp.rbegin();
  if (itr != mp.rend() && itr->first + 2 * t <= tf) {
    cout << itr->first + t;
    return 0;
  }
  for (; itr != mp.rend(); ++itr) {
    auto it = ++itr;
    --itr;
    if (it != mp.rend() && it->first + t < itr->first) {
      mnt = it->first + t;
      break;
    }
    while (it != mp.rend() && it->second == itr->second) {
      ++itr;
      ++it;
    }
    if (itr->first - itr->second < mn) {
      mn = itr->first - itr->second;
      mnt = itr->second - 1;
    }
  }
  cout << mnt;
  return 0;
}
