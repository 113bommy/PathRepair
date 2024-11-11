#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, s;
  cin >> n >> s;
  vector<pair<long long int, pair<long long int, long long int> > > v1, v2;
  long long sum = 0;
  long long sum1 = 0;
  for (int i = 0; i < n; i++) {
    long long int u, v, w;
    cin >> u >> v >> w;
    sum += u;
    if (v > w) {
      v1.push_back(pair<long long int, pair<long long int, long long int> >(
          v, pair<long long int, long long int>(w, u)));
      sum1 += u;
    } else {
      v2.push_back(pair<long long int, pair<long long int, long long int> >(
          w, pair<long long int, long long int>(v, u)));
    }
  }
  long long num = ceil(sum / (double)s);
  long long int p1, p2;
  p1 = sum1 / s;
  p2 = (num - p1) * s;
  p1 = p1 * s;
  long long ans = 0;
  vector<pair<long long int, long long int> > dif1(v1.size());
  vector<pair<long long int, long long int> > dif2(v2.size());
  for (int i = 0; i < v1.size(); i++) {
    dif1[i] = {v1[i].first - v1[i].second.first, i};
  }
  for (int i = 0; i < v2.size(); i++) {
    dif2[i] = {v2[i].first - v2[i].second.first, i};
  }
  sort(dif1.begin(), dif1.end());
  sort(dif2.begin(), dif2.end());
  long long rem = sum1 - p1;
  for (int i = 0; i < v1.size(); i++) {
    long long int idx = dif1[i].second;
    long long int flag = 0;
    long long int r = 0;
    if (rem > 0) {
      ans += min(v1[idx].second.second, rem) * v1[idx].second.first;
      if (rem >= v1[idx].second.second) {
        flag = 1;
        rem = rem - v1[idx].second.second;
      } else {
        r = rem;
        rem = 0;
        flag = 0;
      }
    }
    if (flag == 0) {
      ans += v1[idx].first * (v1[idx].second.second - r);
    }
  }
  for (int i = 0; i < v2.size(); i++) {
    ans += v2[i].first * (v2[i].second.second);
  }
  long long ans1 = ans;
  ans = 0;
  p1 = sum1 / s + 1;
  p2 = (num - p1);
  p2 = p2 * s;
  rem = (sum - sum1) - p2;
  for (int i = 0; i < v2.size(); i++) {
    long long int idx = dif2[i].second;
    long long int flag = 0;
    long long int r = 0;
    if (rem > 0) {
      ans += min(v2[idx].second.second, rem) * v2[idx].second.first;
      if (rem >= v2[idx].second.second) {
        flag = 1;
        rem = rem - v2[idx].second.second;
      } else {
        r = rem;
        rem = 0;
        flag = 0;
      }
    }
    if (flag == 0) {
      ans += v2[idx].first * (v2[idx].second.second - r);
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    ans += v1[i].first * (v1[i].second.second);
  }
  cout << max(ans1, ans);
  return 0;
}
