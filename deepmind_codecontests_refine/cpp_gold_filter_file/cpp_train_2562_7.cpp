#include <bits/stdc++.h>
using namespace std;
long long modulo(long long a, long long b, long long n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
int main() {
  vector<pair<pair<long long, long long>, long long> > v1, v2;
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c == 0)
      v1.push_back({{a, b}, d});
    else
      v2.push_back({{a, c}, d});
  }
  sort(v1.begin(), v1.end());
  vector<bool> visited(n + 1, 0);
  vector<long long> mini(n + 1, (long long)(1e12));
  long long sum = n * (long long)(1e12);
  long long count = 0;
  vector<pair<long long, long long> > ans, ans2;
  for (int i = 0; i < v1.size(); i++) {
    pair<pair<long long, long long>, long long> p = v1[i];
    if (visited[p.first.second] == 0) {
      visited[p.first.second] = 1;
      count++;
    }
    if (mini[p.first.second] > p.second) {
      sum += (p.second - mini[p.first.second]);
      mini[p.first.second] = p.second;
      if (count == n) ans.push_back({p.first.first, sum});
    }
  }
  if (ans.size() != 0) ans2.push_back(ans[0]);
  for (int i = 0; i < ans.size(); i++) {
    if (ans2[ans2.size() - 1].first == ans[i].first) {
      ans2[ans2.size() - 1].second =
          min(ans2[ans2.size() - 1].second, ans[i].second);
    } else
      ans2.push_back(ans[i]);
  }
  vector<bool> visited1(n + 1, 0);
  vector<long long> min1(n + 1, (long long)(1e12));
  long long sum1 = n * (long long)(1e12);
  long long count1 = 0;
  sort(v2.begin(), v2.end());
  reverse(v2.begin(), v2.end());
  long long ansss = (long long)(1e12);
  for (int i = 0; i < v2.size(); i++) {
    pair<pair<long long, long long>, long long> p = v2[i];
    if (visited1[p.first.second] == 0) {
      visited1[p.first.second] = 1;
      count1++;
    }
    if (min1[p.first.second] > p.second) {
      sum1 += (p.second - min1[p.first.second]);
      min1[p.first.second] = p.second;
      if (count1 == n) {
        auto it =
            upper_bound(ans2.begin(), ans2.end(),
                        make_pair(p.first.first - k - 1, (long long)(1e12)));
        if (it != ans2.begin()) {
          it--;
          ansss = min(ansss, sum1 + it->second);
        }
      }
    }
  }
  if (ansss == (long long)(1e12))
    cout << "-1\n";
  else
    cout << ansss << "\n";
  return 0;
}
