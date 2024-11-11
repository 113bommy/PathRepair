#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f3f3f3f3f;
const long long inf = 0xc0c0c0c0c0c0c0c0;
const double pi = acos(-1);
const double log100 = log(100);
int N, M;
const int MAX = 1e4 + 7;
struct tree {
  int x, h;
  double pl, pr;
} arr[MAX * 10];
struct mu {
  int x;
  double val;
} brr[MAX];
double tool[MAX];
bool operator<(mu m1, mu m2) { return m1.x < m2.x; }
vector<pair<int, int> > V;
int pMax[MAX * 10];
bool ok(int x) {
  int k = upper_bound(V.begin(), V.end(), make_pair(x, INF)) - V.begin();
  k--;
  if (k < 0)
    return 1;
  else
    return pMax[k] < x;
}
int main() {
  scanf("%d%d", &N, &M);
  int sz = 0;
  for (int i = 0; i < N; i++) {
    int l, r;
    scanf("%d%d%d%d", &arr[sz].x, &arr[sz].h, &l, &r);
    if (l == 100)
      V.push_back(make_pair(arr[sz].x - arr[sz].h, arr[sz].x));
    else if (r == 100)
      V.push_back(make_pair(arr[sz].x, arr[sz].x + arr[sz].h));
    else {
      arr[sz].pl = log(100 - l) - log100;
      arr[sz].pr = log(100 - r) - log100;
      sz++;
    }
  }
  sort(V.begin(), V.end());
  int last = inf;
  for (int i = 0; i < V.size(); i++) {
    last = max(last, V[i].second);
    pMax[i] = last;
  }
  N = sz;
  sz = 0;
  for (int i = 0; i < M; i++) {
    int v;
    scanf("%d%d", &brr[sz].x, &v);
    if (ok(brr[sz].x)) brr[sz++].val = log(v);
  }
  M = sz;
  sort(brr, brr + M);
  for (int i = 0; i < N; i++) {
    int start = lower_bound(brr, brr + M, mu{arr[i].x - arr[i].h, 0}) - brr;
    int mid1 = lower_bound(brr, brr + M, mu{arr[i].x, 0}) - brr;
    int mid2 = upper_bound(brr, brr + M, mu{arr[i].x, 0}) - brr;
    int end = upper_bound(brr, brr + M, mu{arr[i].x + arr[i].h, 0}) - brr;
    tool[start] += arr[i].pl;
    tool[mid1] -= arr[i].pl;
    tool[mid2] += arr[i].pr;
    tool[end] -= arr[i].pr;
  }
  double sum = 0;
  double psum = 0;
  for (int i = 0; i < M; i++) {
    psum += tool[i];
    sum += exp(psum + brr[i].val);
  }
  printf("%.6lf\n", sum);
  return 0;
}
