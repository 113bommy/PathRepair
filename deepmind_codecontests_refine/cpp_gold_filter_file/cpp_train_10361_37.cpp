#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 1 << 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 10;
long long Max[maxn * 4];
long long GetMax(int rt, int L, int R, int l, int r) {
  if (l <= L && R <= r) return Max[rt];
  int mid = (L + R) / 2;
  long long ans = 0;
  if (l <= mid) ans = max(ans, GetMax(rt << 1, L, mid, l, r));
  if (r > mid) ans = max(ans, GetMax(rt << 1 | 1, mid + 1, R, l, r));
  return ans;
}
void Updata(int rt, int L, int R, int pos, long long val) {
  if (L == R && pos == L) {
    Max[rt] = val;
    return;
  }
  int mid = (L + R) / 2;
  if (pos <= mid) Updata(rt << 1, L, mid, pos, val);
  if (pos > mid) Updata(rt << 1 | 1, mid + 1, R, pos, val);
  Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
  return;
}
struct Item {
  long long val;
  int id;
  bool operator<(const Item& rhs) const {
    if (this->val != rhs.val) return this->val < rhs.val;
    return this->id > rhs.id;
  }
} tmp;
vector<Item> vec;
long long r, h;
int n;
const double pi = 3.1415926;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> r >> h;
    tmp.val = r * r * h;
    tmp.id = i;
    vec.push_back(tmp);
  }
  long long sum = 0;
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; ++i) {
    int id = vec[i].id;
    long long best = GetMax(1, 0, n - 1, 0, id);
    long long ans = best + vec[i].val;
    Updata(1, 0, n - 1, id, ans);
  }
  cout.precision(12);
  cout << fixed << pi * GetMax(1, 0, n - 1, 0, n - 1) << endl;
  return 0;
}
