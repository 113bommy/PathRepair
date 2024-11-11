#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 18) + 5;
int N, M, K;
int cost[MAXN];
bool likeA[MAXN];
bool likeB[MAXN];
vector<pair<long long, long long> > both;
vector<pair<long long, long long> > onlyA;
vector<pair<long long, long long> > onlyB;
struct BIT {
  long long cnt[MAXN];
  long long sum[MAXN];
  void update(int pos, int c, long long s) {
    while (pos < MAXN) {
      cnt[pos] += c;
      sum[pos] += s;
      pos += pos & -pos;
    }
  }
  long long get_first_x(long long x) {
    if (!x) return 0;
    long long cntsum = 0;
    long long valsum = 0;
    int idx = 0;
    for (int a = 18; a >= 0; a--) {
      int tidx = idx | (1 << a);
      if (cntsum + cnt[tidx] < x) {
        cntsum += cnt[tidx];
        valsum += sum[tidx];
        idx = tidx;
      }
    }
    return valsum;
  }
} ds;
pair<int, int> sorted[MAXN];
int sortorder[MAXN];
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cin >> N >> M >> K;
  for (int a = 1; a <= N; a++) {
    cin >> cost[a];
    sorted[a] = {cost[a], a};
  }
  sort(sorted + 1, sorted + N + 1);
  for (int a = 1; a <= N; a++) {
    sortorder[sorted[a].second] = a;
  }
  int A;
  cin >> A;
  while (A--) {
    int x;
    cin >> x;
    likeA[x] = true;
  }
  int B;
  cin >> B;
  while (B--) {
    int x;
    cin >> x;
    likeB[x] = true;
  }
  int totds = 0;
  for (int a = 1; a <= N; a++) {
    if (likeA[a] && likeB[a]) {
      both.push_back({cost[a], a});
    } else if (likeA[a]) {
      onlyA.push_back({cost[a], a});
      ds.update(sortorder[a], 1, cost[a]);
      totds++;
    } else if (likeB[a]) {
      onlyB.push_back({cost[a], a});
      ds.update(sortorder[a], 1, cost[a]);
      totds++;
    } else {
      ds.update(sortorder[a], 1, cost[a]);
      totds++;
    }
  }
  if (K > int(both.size() + onlyA.size()) ||
      K > int(both.size() + onlyB.size())) {
    cout << -1;
    return 0;
  }
  sort(both.begin(), both.end());
  sort(onlyA.begin(), onlyA.end());
  reverse(onlyA.begin(), onlyA.end());
  sort(onlyB.begin(), onlyB.end());
  reverse(onlyB.begin(), onlyB.end());
  while ((int)both.size() > K) {
    pair<int, int> back = both.back();
    both.pop_back();
    ds.update(sortorder[back.second], 1, back.first);
    totds++;
  }
  long long basecost = 0;
  long long ans = 1e18;
  for (pair<int, int> p : both) {
    basecost += p.first;
  }
  for (int a = K; a >= 0; a--) {
    int remainK = K - a;
    int remainM = M - a - 2 * remainK;
    if (a <= (int)both.size()) {
      if (0 <= remainM && remainM <= totds) {
        long long xsum = ds.get_first_x(remainM);
        long long cost = basecost + xsum;
        ans = min(ans, cost);
      }
      if (!both.empty()) {
        totds++;
        basecost -= both.back().first;
        ds.update(sortorder[both.back().second], 1, both.back().first);
        both.pop_back();
      }
    }
    if (onlyA.empty() || onlyB.empty()) {
      break;
    } else {
      totds -= 2;
      basecost += onlyA.back().first;
      basecost += onlyB.back().first;
      ds.update(sortorder[onlyA.back().second], -1, -onlyA.back().first);
      ds.update(sortorder[onlyB.back().second], -1, -onlyB.back().first);
      onlyA.pop_back();
      onlyB.pop_back();
    }
  }
  if (ans == 1e18) {
    cout << "-1\n";
  } else {
    cout << ans << "\n";
  }
}
