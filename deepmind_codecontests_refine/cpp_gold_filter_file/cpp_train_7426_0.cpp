#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
const int INF = (int)1e9;
const long long INF64 = (long long)1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
vector<int> t;
vector<vector<int> > tr;
vector<pair<int, int> > idx;
vector<char> used;
vector<vector<long long> > fenw;
int h, m, n;
long long sum(int x, int r) {
  long long result = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) result += fenw[x][r];
  return result;
}
void inc(int x, int i, long long delta, int nn) {
  for (; i < nn; i = (i | (i + 1))) fenw[x][i] += delta;
}
long long sum(int x, int l, int r) { return sum(x, r) - sum(x, l - 1); }
int main() {
  scanf("%d%d%d", &h, &m, &n);
  t.assign(h, -1);
  used.assign(h, 0);
  map<int, pair<int, int> > f;
  idx.assign(h, make_pair(-1, -1));
  for (int i = 0; i < int(h); ++i) {
    if (!used[i]) {
      tr.push_back(vector<int>());
      int t = i;
      while (!used[t]) {
        used[t] = true;
        (tr.back()).push_back(0);
        idx[t] = make_pair((int)(tr).size() - 1, (int)(tr.back()).size() - 1);
        t = (t + m) % h;
      }
    }
  }
  fenw.resize((int)(tr).size());
  for (int i = 0; i < int((int)(tr).size()); ++i)
    fenw[i].assign((int)(tr[i]).size() * 4, 0);
  long long ans = 0;
  for (int i = 0; i < int(n); ++i) {
    char op;
    scanf("\n%c", &op);
    if (op == '-') {
      int id;
      scanf("%d", &id);
      pair<int, int> hash = f[id];
      int x = hash.first;
      int y = hash.second;
      inc(x, y, -1, (int)(fenw[x]).size());
    } else {
      int id, hash;
      scanf("%d%d", &id, &hash);
      int x = idx[hash].first;
      int y = idx[hash].second;
      int l = 0, r = (int)(tr[x]).size() - 1;
      while (r - l > 1) {
        int mid = (l + r) / 2;
        long long tsum = 0;
        if (y + mid >= (int)(tr[x]).size()) {
          int d = (y + mid) % (int)(tr[x]).size();
          tsum += sum(x, y, (int)(tr[x]).size() - 1);
          tsum += sum(x, 0, d);
        } else
          tsum += sum(x, y, y + mid);
        if (mid + 1 - tsum >= 1)
          r = mid;
        else
          l = mid;
      }
      int pos = -1;
      long long tsum = 0;
      if (y + r >= (int)(tr[x]).size()) {
        int d = (r + y) % (int)(tr[x]).size();
        tsum += sum(x, y, (int)(tr[x]).size() - 1);
        tsum += sum(x, 0, d);
      } else
        tsum += sum(x, y, y + r);
      if (r + 1 - tsum >= 1) pos = r;
      tsum = 0;
      if (y + l >= (int)(tr[x]).size()) {
        int d = (l + y) % (int)(tr[x]).size();
        tsum += sum(x, y, (int)(tr[x]).size() - 1);
        tsum += sum(x, 0, d);
      } else
        tsum += sum(x, y, y + l);
      if (l + 1 - tsum >= 1) pos = l;
      inc(x, (y + pos) % (int)(tr[x]).size(), 1, (int)(fenw[x]).size());
      f[id] = make_pair(x, (y + pos) % (int)(tr[x]).size());
      ans += pos;
    }
  }
  cout << ans;
  return 0;
}
