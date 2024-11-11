#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > diffs;
long long int su[100500];
int n, s;
long long int kek(long long int res) {
  long long int ans = res;
  su[n - 1] = 1ll * diffs.back().first * diffs.back().second;
  for (int i = n - 2; i >= 0; i--) {
    su[i] = su[i + 1] + diffs[i].first * 1ll * diffs[i].second;
  }
  long long int w = 0;
  long long int wa = 0;
  for (int i = 0; i < n; i++) {
    if (diffs[i].first < 0) {
      w += diffs[i].second;
    } else {
      long long int aim = (w + s - 1) / s * s;
      while (i < n && w + diffs[i].second <= aim) {
        w += diffs[i].second;
        wa += diffs[i].second * 1ll * diffs[i].first;
        i++;
      }
      if (w == aim) {
        ans = max(ans, res + su[i]);
      } else {
        long long int x = aim - w;
        ans = max(ans, res + wa + su[i] - x * diffs[i].first);
      }
      break;
    }
  }
  return ans;
}
int main() {
  cin >> n >> s;
  long long int sum = 0;
  long long int res = 0;
  long long int res1 = 0;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    sum += a;
    res += 1ll * a * b;
    res1 += 1ll * a * c;
    diffs.push_back({c - b, a});
  }
  long long int kol = (sum + s - 1) / s;
  if (kol * s > sum) diffs.push_back({0, kol * s - sum});
  n = diffs.size();
  sort(diffs.begin(), diffs.end());
  long long int ans = res;
  if (diffs[0].first >= 0) {
    for (auto x : diffs) {
      res += 1ll * x.first * x.second;
    }
    cout << res;
    return 0;
  }
  if (diffs.back().first <= 0) {
    cout << res;
    return 0;
  }
  long long int danil = kek(res);
  reverse(diffs.begin(), diffs.end());
  for (auto &x : diffs) {
    x.first *= -1;
  }
  cout << max(danil, kek(res1));
  return 0;
}
