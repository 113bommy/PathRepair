#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-12;
const int maxn = 500000 + 1912;
int n, Q;
int a[maxn];
pair<int, int> q[maxn];
void ReadData() {
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= Q; i++) scanf("%d%d", &q[i].first, &q[i].second);
}
map<int, int> RR;
void Init() {
  for (int i = 1; i <= n; i++) RR[a[i]];
  for (int i = 1; i <= Q; i++) RR[q[i].second];
  int cur = 0;
  for (map<int, int>::iterator it = RR.begin(); it != RR.end(); it++) {
    it->second = ++cur;
  }
  for (int i = 1; i <= n; i++) a[i] = RR[a[i]];
  for (int i = 1; i <= Q; i++) q[i].second = RR[q[i].second];
}
const int md = 1e9 + 9;
const int MX = 900000;
struct data {
  int val, cnt;
} bit[maxn * 3];
data Combine(const data &a, const data &b) {
  data res;
  if (a.val > b.val)
    res = a;
  else if (a.val < b.val)
    res = b;
  else
    res = (data){a.val, (a.cnt + b.cnt) % md};
  return res;
}
void Update(int x, data val) {
  for (; x <= MX; x += x & -x) bit[x] = Combine(bit[x], val);
}
data Query(int x) {
  data res = (data){0, 1};
  for (; x > 0; x -= x & -x) res = Combine(res, bit[x]);
  res.val++;
  return res;
}
void Update2(int x, data val) {
  for (; x > 0; x -= x & -x) bit[x] = Combine(bit[x], val);
}
data Query2(int x) {
  data res = (data){0, 1};
  for (; x <= MX; x += x & -x) res = Combine(res, bit[x]);
  res.val++;
  return res;
}
void InitBIT() {
  for (int i = 1; i <= MX; i++) bit[i] = (data){0, 0};
}
data Up[maxn], Down[maxn];
void InitLIS() {
  InitBIT();
  for (int i = 1; i <= n; i++) {
    Up[i] = Query(a[i] - 1);
    Update(a[i], Up[i]);
  }
  InitBIT();
  for (int i = n; i >= 1; i--) {
    Down[i] = Query2(a[i] + 1);
    Update2(a[i], Down[i]);
  }
}
int res[maxn];
vector<int> contain[maxn];
data dpUp[maxn], dpDown[maxn];
void Process() {
  Init();
  InitLIS();
  data Lis = (data){0, 1};
  for (int i = 1; i <= n; i++) Lis = Combine(Lis, Up[i]);
  for (int i = 1; i <= Q; i++) {
    int pos = q[i].first;
    if (Down[pos].val + Up[pos].val == Lis.val + 1 &&
        1LL * Down[pos].cnt * Up[pos].cnt % md == Lis.cnt)
      res[i] = Lis.val - 1;
    else
      res[i] = Lis.val;
  }
  for (int i = 1; i <= Q; i++) contain[q[i].first].push_back(i);
  InitBIT();
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < ((int)contain[i].size()); j++) {
      int id = contain[i][j];
      int val = q[id].second;
      dpUp[i] = Query(val - 1);
    }
    Update(a[i], Query(a[i] - 1));
  }
  InitBIT();
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < ((int)contain[i].size()); j++) {
      int id = contain[i][j];
      int val = q[i].second;
      dpDown[i] = Query2(val + 1);
    }
    Update2(a[i], Query2(a[i] + 1));
  }
  for (int i = 1; i <= Q; i++)
    res[i] = max(res[i], dpDown[i].val + dpUp[i].val - 1);
  for (int i = 1; i <= Q; i++) cout << res[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ReadData();
  Process();
}
