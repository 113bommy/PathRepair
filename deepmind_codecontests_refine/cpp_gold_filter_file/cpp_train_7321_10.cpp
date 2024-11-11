#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dj[] = {0, 1, 0, -1, -1, 1, -1, 1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const long double EPS = 1e-7;
struct Shoe {
  long long price, size, idx;
  bool operator<(Shoe other) const { return size < other.size; }
};
struct Customer {
  long long money, size, idx;
  bool operator<(Customer other) const { return size < other.size; }
};
int n, m;
vector<Customer> cust;
vector<long long> shoeSize;
vector<Shoe> shoe;
vector<vector<vector<long long> > > mem(
    1e5 + 5, vector<vector<long long> >(2, vector<long long>(2, -1)));
long long solve(int idx, bool same, bool samep) {
  if (idx == m) return 0;
  long long& ret = mem[idx][same][samep];
  if (~ret) return ret;
  ret = 0;
  auto it = lower_bound(shoeSize.begin(), shoeSize.end(), cust[idx].size);
  if (same && it != shoeSize.end() && *it == cust[idx].size &&
      cust[idx].money >= shoe[it - shoeSize.begin()].price) {
    bool nxtSame = true;
    bool nxtSamep = true;
    if (idx < m - 1) {
      if (cust[idx + 1].size == cust[idx].size) {
        nxtSame = false;
        nxtSamep = samep;
      }
      if (cust[idx + 1].size == cust[idx].size + 1) {
        nxtSame = samep;
        nxtSamep = true;
      }
    }
    ret = max(ret, solve(idx + 1, nxtSame, nxtSamep) +
                       shoe[it - shoeSize.begin()].price);
  }
  it = lower_bound(shoeSize.begin(), shoeSize.end(), cust[idx].size + 1);
  if (samep && it != shoeSize.end() && *it == cust[idx].size + 1 &&
      cust[idx].money >= shoe[it - shoeSize.begin()].price) {
    bool nxtSame = true;
    bool nxtSamep = true;
    if (idx < m - 1) {
      if (cust[idx + 1].size == cust[idx].size) {
        nxtSame = same;
        nxtSamep = false;
      }
      if (cust[idx + 1].size == cust[idx].size + 1) {
        nxtSame = false;
        nxtSamep = true;
      }
    }
    ret = max(ret, solve(idx + 1, nxtSame, nxtSamep) +
                       shoe[it - shoeSize.begin()].price);
  }
  bool nxtSame = true;
  bool nxtSamep = true;
  if (idx < m - 1) {
    if (cust[idx + 1].size == cust[idx].size) {
      nxtSame = same;
      nxtSamep = samep;
    }
    if (cust[idx + 1].size == cust[idx].size + 1) {
      nxtSame = samep;
      nxtSamep = true;
    }
  }
  ret = max(ret, solve(idx + 1, nxtSame, nxtSamep));
  return ret;
}
map<int, int> path;
void build(int idx, bool same, bool samep) {
  if (idx == m) return;
  long long ret = -1;
  bool mxSame = same, mxSamep = samep;
  int bought = -1;
  auto it = lower_bound(shoeSize.begin(), shoeSize.end(), cust[idx].size);
  if (same && it != shoeSize.end() && *it == cust[idx].size &&
      cust[idx].money >= shoe[it - shoeSize.begin()].price) {
    bool nxtSame = true;
    bool nxtSamep = true;
    if (idx < m - 1) {
      if (cust[idx + 1].size == cust[idx].size) {
        nxtSame = false;
        nxtSamep = samep;
      }
      if (cust[idx + 1].size == cust[idx].size + 1) {
        nxtSame = samep;
        nxtSamep = true;
      }
    }
    long long x =
        solve(idx + 1, nxtSame, nxtSamep) + shoe[it - shoeSize.begin()].price;
    if (x > ret) {
      ret = x;
      mxSame = nxtSame;
      mxSamep = nxtSamep;
      bought = shoe[it - shoeSize.begin()].idx;
    }
  }
  it = lower_bound(shoeSize.begin(), shoeSize.end(), cust[idx].size + 1);
  if (samep && it != shoeSize.end() && *it == cust[idx].size + 1 &&
      cust[idx].money >= shoe[it - shoeSize.begin()].price) {
    bool nxtSame = true;
    bool nxtSamep = true;
    if (idx < m - 1) {
      if (cust[idx + 1].size == cust[idx].size) {
        nxtSame = same;
        nxtSamep = false;
      }
      if (cust[idx + 1].size == cust[idx].size + 1) {
        nxtSame = false;
        nxtSamep = true;
      }
    }
    long long x =
        solve(idx + 1, nxtSame, nxtSamep) + shoe[it - shoeSize.begin()].price;
    if (x > ret) {
      ret = x;
      mxSame = nxtSame;
      mxSamep = nxtSamep;
      bought = shoe[it - shoeSize.begin()].idx;
    }
  }
  bool nxtSame = true;
  bool nxtSamep = true;
  if (idx < m - 1) {
    if (cust[idx + 1].size == cust[idx].size) {
      nxtSame = same;
      nxtSamep = samep;
    }
    if (cust[idx + 1].size == cust[idx].size + 1) {
      nxtSame = samep;
      nxtSamep = true;
    }
  }
  long long x = solve(idx + 1, nxtSame, nxtSamep);
  if (x > ret) {
    ret = x;
    mxSame = nxtSame;
    mxSamep = nxtSamep;
    bought = -1;
  }
  if (bought != -1) path[cust[idx].idx] = bought;
  build(idx + 1, mxSame, mxSamep);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  shoeSize.resize(n);
  shoe.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> shoe[i].price >> shoe[i].size;
    shoe[i].idx = i;
  }
  sort(shoe.begin(), shoe.end());
  for (int i = 0; i < n; i++) {
    shoeSize[i] = shoe[i].size;
  }
  cin >> m;
  cust.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> cust[i].money >> cust[i].size;
    cust[i].idx = i;
  }
  sort(cust.begin(), cust.end());
  cout << solve(0, true, true) << endl;
  build(0, true, true);
  cout << path.size() << endl;
  for (auto& i : path) cout << i.first + 1 << " " << i.second + 1 << endl;
  cin.ignore(), cin.get();
}
