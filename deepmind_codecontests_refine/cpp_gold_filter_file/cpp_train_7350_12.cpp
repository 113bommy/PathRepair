#include <bits/stdc++.h>
using namespace std;
long long int N, M;
long long int K;
vector<pair<long long int, long long int> > fire;
bool full_fire(vector<pair<long long int, long long int> >& seg,
               long long int edge) {
  if (seg.size() == 0) return false;
  sort(seg.begin(), seg.end());
  long long int ret = 0;
  long long int last = 0;
  for (long long int i = 0; i < seg.size(); i++) {
    long long int l = max(seg[i].first, last + 1);
    ret += max(0LL, seg[i].second - l + 1);
    last = max(last, seg[i].second);
  }
  return ret >= edge;
}
bool check(long long int t) {
  vector<long long int> x, y;
  x.push_back(1), x.push_back(N);
  y.push_back(1), y.push_back(M);
  for (long long int i = 0; i < fire.size(); i++) {
    x.push_back(max(1LL, fire[i].first - t - 1));
    x.push_back(min(N, fire[i].first + t + 1));
    y.push_back(max(1LL, fire[i].second - t - 1));
    y.push_back(min(M, fire[i].second + t + 1));
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  long long int left_x = 1000000009, right_x = -1, top_y = -1,
                bot_y = 1000000009;
  for (long long int i = 0; i < x.size(); i++) {
    vector<pair<long long int, long long int> > alight;
    for (long long int k = 0; k < fire.size(); k++) {
      if (abs(fire[k].first - x[i]) > t) continue;
      alight.push_back(
          make_pair(max(1LL, fire[k].second - t), min(fire[k].second + t, M)));
    }
    if (!full_fire(alight, M)) {
      left_x = min(left_x, x[i]);
      right_x = max(right_x, x[i]);
    }
  }
  for (long long int i = 0; i < y.size(); i++) {
    vector<pair<long long int, long long int> > alight;
    for (long long int k = 0; k < fire.size(); k++) {
      if (abs(fire[k].second - y[i]) > t) continue;
      alight.push_back(
          make_pair(max(1LL, fire[k].first - t), min(fire[k].first + t, N)));
    }
    if (!full_fire(alight, N)) {
      top_y = max(top_y, y[i]);
      bot_y = min(bot_y, y[i]);
    }
  }
  if (left_x == 1000000009) return true;
  return (right_x - left_x <= 2 * t) && (top_y - bot_y <= 2 * t);
}
int main() {
  cin >> N >> M;
  cin >> K;
  for (long long int i = 0; i < K; i++) {
    long long int x, y;
    cin >> x >> y;
    fire.push_back(make_pair(x, y));
  }
  long long int minim = 0, maxim = 1000000009;
  long long int ans = maxim * 10;
  while (minim <= maxim) {
    long long int mid = (minim + maxim) / 2;
    if (check(mid)) {
      maxim = mid - 1;
      ans = min(ans, mid);
    } else {
      minim = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
