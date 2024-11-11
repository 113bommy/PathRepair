#include <bits/stdc++.h>
using namespace std;
void setIO() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long double PI = 4 * atan((long double)1);
const int INF = 1e9 + 7;
const int MAX = 1e5 + 7;
struct dt {
  int vl, id;
};
bool comp(dt a, dt b) { return (a.vl > b.vl); }
vector<dt> ky, ct;
vector<int> vc;
int main() {
  setIO();
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    int t, pr;
    cin >> t >> pr;
    if (t & 1)
      ky.push_back({pr, i});
    else
      ct.push_back({pr, i});
  }
  sort(ky.begin(), ky.end(), comp);
  sort(ct.begin(), ct.end(), comp);
  ky.push_back({0, 0});
  int ksz = (signed)ky.size() - 2, csz = (signed)ct.size() - 1, k = 0, c = 0,
      rs = 0;
  while (k <= ksz || c <= csz) {
    if (!p) break;
    if (p == 1) {
      if (k <= ksz) {
        rs += ky[k].vl;
        vc.emplace_back(ky[k].id);
      }
      break;
    } else {
      if (k > ksz) {
        vc.emplace_back(ct[c].id);
        rs += ct[c++].vl;
        p -= 2;
      } else if (c > csz) {
        vc.emplace_back(ky[k].id);
        rs += ky[k++].vl;
        p--;
      } else if (ky[k].vl + ky[k + 1].vl < ct[c].vl) {
        vc.emplace_back(ct[c].id);
        rs += ct[c++].vl;
        p -= 2;
      } else {
        vc.emplace_back(ky[k].id);
        rs += ky[k++].vl;
        p--;
      }
    }
  }
  cout << rs << endl;
  for (auto x : vc) cout << x + 1 << " ";
  cout << endl;
}
