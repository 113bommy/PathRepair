#include <bits/stdc++.h>
using namespace std;
const long long DIV = 1000000007;
const int MAX_N = 1000000;
int N;
long long D1[MAX_N + 1];
int arr[MAX_N + 1];
struct SEG {
  struct NODE {
    NODE(int l, int r, int sum) : l(l), r(r), sum(sum) {}
    int l, r;
    int sum;
  };
  int SZ;
  vector<NODE> seg;
  void Init(int x) {
    SZ = x;
    seg.push_back({-1, -1, 0});
    init(0, 1, SZ);
  }
  void init(int idx, int s, int e) {
    if (s == e) return;
    seg[idx].l = seg.size();
    seg.push_back({-1, -1, 0});
    seg[idx].r = seg.size();
    seg.push_back({-1, -1, 0});
    init(seg[idx].l, s, (s + e) / 2);
    init(seg[idx].r, (s + e) / 2 + 1, e);
  }
  void Update(int x, int y) { update(0, 1, SZ, x, y); }
  void update(int idx, int s, int e, int x, int y) {
    seg[idx].sum += y;
    if (s == e) return;
    if (x <= (s + e) / 2) {
      update(seg[idx].l, s, (s + e) / 2, x, y);
    } else {
      update(seg[idx].r, (s + e) / 2 + 1, e, x, y);
    }
  }
  int Sum(int x, int y) { return sum(0, 1, SZ, x, y); }
  int sum(int idx, int s, int e, int x, int y) {
    if (x <= s && e <= y) return seg[idx].sum;
    if (x > e || y < s) return 0;
    return sum(seg[idx].l, s, (s + e) / 2, x, y) +
           sum(seg[idx].r, (s + e) / 2 + 1, e, x, y);
  }
};
SEG Seg;
long long ans, prv;
long long per[MAX_N + 1];
void pl(long long x) {
  x = x % DIV;
  ans = (ans + x) % DIV;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
  }
  long long p = 1;
  per[1] = (long long)1;
  for (long long i = 2; i <= (long long)N; i++) {
    if (i != 2) p = p * (long long)i % DIV;
    per[i] = (p * (long long)2) % DIV;
    D1[i] = (i * (i - 1) / 2 % DIV) * p % DIV;
  }
  Seg.Init(N);
  for (int i = 1; i <= N; i++) {
    Seg.Update(i, 1);
  }
  for (int i = 1; i <= N; i++) {
    long long x = (long long)Seg.Sum(1, arr[i]);
    long long l = (long long)(N - i + 1);
    pl((x - 1) * D1[l - 1]);
    pl(((x - 1) * prv % DIV) * per[l - 1]);
    pl(((x - 2) * (x - 1) / 2 % DIV) * per[l - 1]);
    prv = (prv + x - 1) % DIV;
    Seg.Update(arr[i], -1);
  }
  pl(prv);
  cout << ans;
  return 0;
}
