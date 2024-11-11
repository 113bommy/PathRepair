#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll INF = 1LL << 60;
using vc = vector<char>;
using vi = vector<int>;
int N;
unordered_map<int, int> occ;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> N;
  for (int i = (0); i < (N); ++i) {
    int a;
    cin >> a;
    occ[a]++;
  }
  vector<pair<int, int>> stacks;
  for (auto p : occ) {
    stacks.push_back({p.second, p.first});
  }
  sort(stacks.begin(), stacks.end(), greater<pair<int, int>>());
  int SS = stacks.size();
  vi cumsum(SS + 1);
  cumsum[SS] = 0;
  for (int i = (SS)-1; i >= (0); --i) {
    cumsum[i] = stacks[i].first + cumsum[i + 1];
  }
  int ba = 0;
  int bh = 0;
  for (int h = (1); h < (N + 1); ++h) {
    int lo = 0;
    int hi = stacks.size();
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (stacks[mid].first > h)
        lo = mid + 1;
      else
        hi = mid;
    }
    int w = lo + cumsum[lo] / h;
    if ((w >= h) && (w * h > ba)) {
      ba = w * h;
      bh = h;
    }
  }
  int h = bh;
  int w = ba / bh;
  int cur = 0;
  vector<vi> data(h, vi(w));
  int k = h;
  for (int i = (0); i < (ba); ++i) {
    while (stacks[cur].first == 0 || k == 0) {
      ++cur;
      k = h;
    };
    data[i % h][i / h] = stacks[cur].second;
    --stacks[cur].first;
    --k;
  }
  cout << ba << endl;
  cout << h << " " << w << endl;
  for (int i = (0); i < (h); ++i) {
    for (int j = (0); j < (w); ++j) {
      cout << data[i][(j - i + w) % w] << " ";
    }
    cout << endl;
  }
}
