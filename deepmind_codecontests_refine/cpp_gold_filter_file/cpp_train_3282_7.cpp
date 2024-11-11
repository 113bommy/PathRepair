#include <bits/stdc++.h>
using namespace std;
struct BIT {
  vector<int> sum;
  int len;
  void Init(int _len) {
    len = _len + 5;
    sum.resize(len, 0);
  }
  void Add(int pos, int how) {
    pos += 1;
    for (; pos < len; pos += (pos & (-pos))) sum[pos] += how;
  }
  int Get(int pos) {
    pos += 1;
    int res = 0;
    for (; pos > 0; pos -= (pos & (-pos))) res += sum[pos];
    return res;
  }
};
int n;
vector<pair<int, pair<int, int> > > in;
map<int, vector<int> > touch;
map<int, BIT> vals;
int GetIdx(int x, int t) {
  vector<int>& tim = touch[x];
  return lower_bound(tim.begin(), tim.end(), t) - tim.begin();
}
int main() {
  scanf("%d", &n);
  in.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &in[i].first, &in[i].second.first, &in[i].second.second);
    touch[in[i].second.second].push_back(in[i].second.first);
  }
  for (auto& el : touch) {
    sort(el.second.begin(), el.second.end());
    el.second.erase(unique(el.second.begin(), el.second.end()),
                    el.second.end());
    BIT& b = vals[el.first];
    b.Init(((int)(el.second).size()) + 1);
  }
  for (int i = 0; i < n; ++i) {
    int t = in[i].second.first;
    int x = in[i].second.second;
    if (in[i].first == 1) {
      int idx = GetIdx(x, t);
      vals[x].Add(idx, +1);
    }
    if (in[i].first == 2) {
      int idx = GetIdx(x, t);
      vals[x].Add(idx, -1);
    }
    if (in[i].first == 3) {
      int idx = GetIdx(x, t);
      int cnt = vals[x].Get(idx);
      (cnt) = max((cnt), (0));
      printf("%d\n", cnt);
    }
  }
  return 0;
}
