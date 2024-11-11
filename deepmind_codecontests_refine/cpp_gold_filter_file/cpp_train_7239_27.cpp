#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:30000000")
using namespace std;
const double EPS = 1E-8;
const int INF = (int)1E+9;
const int maxn = 7;
struct cnt {
  int h, l, v, a;
  cnt(int H, int L, int V, int A) {
    h = H;
    l = L;
    v = V;
    a = A;
  }
};
vector<cnt> vk[maxn];
int ANS = 0;
int n;
bool check;
int FLOW;
void rec1(vector<pair<int, int> > vv, vector<int> apf) {
  int ans = apf[0];
  int p = apf[1];
  int flow = apf[2];
  if (vv.size() == 1 && vv[0].first == n - 1) {
    if (FLOW != flow) return;
    check = true;
    ANS = max(ans, ANS);
    return;
  }
  sort(vv.begin(), vv.end());
  int k = vv[0].first;
  int aa = vv[0].second;
  for (int i = 0; i < vk[k].size(); i++) {
    int f = vk[k][i].v;
    int l = vk[k][i].l;
    int h = vk[k][i].h;
    int a = vk[k][i].a;
    if (f < p) continue;
    if (aa < l) continue;
    for (int j = max(1, l); j <= min(aa, h); j++) {
      bool TCheck = false;
      int p1 = p;
      vector<pair<int, int> > vvs = vv;
      if (j == aa) {
        swap(vvs[0], vvs[vvs.size() - 1]);
        vvs.pop_back();
        p1 = 0;
      } else {
        vvs[0].second -= j;
        p1 = f + 1;
      }
      for (int t = 0; t < vvs.size(); t++)
        if (vvs[t].first == f) {
          vvs[t].second += j;
          TCheck = true;
        }
      if (TCheck == false) vvs.push_back(make_pair(f, j));
      int bANS = ans + a + j * j;
      vector<int> vvvv;
      vvvv.push_back(bANS);
      vvvv.push_back(p1);
      int flows = flow;
      if (l != 0) flows++;
      vvvv.push_back(flows);
      rec1(vvs, vvvv);
    }
  }
}
bool rec(int cap) {
  check = false;
  vector<pair<int, int> > vv;
  vv.push_back(make_pair(0, cap));
  vector<int> vs;
  vs.push_back(0);
  vs.push_back(0);
  vs.push_back(0);
  rec1(vv, vs);
  return check;
}
void rec2(int k) {
  if (k == n - 1) {
    check = true;
    return;
  }
  for (int i = 0; i < vk[k].size(); i++) {
    int f = vk[k][i].v;
    int l = vk[k][i].l;
    if (l == 0) rec2(f);
  }
}
int main() {
  bool CHECK = true;
  cin >> n;
  FLOW = 0;
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    int s, h, l, v, f, a;
    cin >> s;
    cin >> f >> l >> h >> a;
    f--;
    s--;
    if (l) CHECK = false;
    if (l) FLOW++;
    cnt c(h, l, f, a);
    vk[s].push_back(c);
  }
  if (CHECK) {
    cout << "0 0\n";
    return 0;
  }
  for (int i = 0; i <= 25; i++)
    if (rec(i)) {
      cout << i << ' ' << ANS << '\n';
      return 0;
    }
  cout << "-1 -1\n";
  return 0;
}
