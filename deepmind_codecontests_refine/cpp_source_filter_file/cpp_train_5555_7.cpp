#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long mp[N];
struct querry {
  long long f, s, t;
};
long long a[N];
long long res[N];
long long cur;
long long block;
querry vp[N];
bool cmp(querry a, querry b) {
  long long x = a.f / block, y = b.f / block;
  if (x != y) return x < y;
  return a.s < b.s;
}
inline void update(long long x) {
  if (mp[x] == x) {
    --cur;
  }
  cur += (++mp[x] == x);
}
inline void update1(long long x) {
  if (mp[x] == x) {
    --cur;
  }
  cur += (--mp[x] == x);
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, l, r, left = 1, right = 0;
  cin >> n >> m;
  block = sqrtl(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > N) a[i] = 0;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> vp[i].f >> vp[i].s;
    vp[i].t = i;
  }
  sort(vp + 1, vp + m + 1, cmp);
  for (int i = 1; i <= m; ++i) {
    long long x = vp[i].f;
    long long y = vp[i].s;
    while (right < y) {
      ++right;
      update(a[right]);
    }
    while (right > y) {
      update1(a[right]);
      --right;
    }
    while (left < x) {
      update1(a[left]);
      ++left;
    }
    while (left > x) {
      --left;
      update(a[left]);
    }
    res[vp[i].t] = cur;
  }
  for (int i = 1; i <= m; ++i) {
    cout << res[i] << "\n";
  }
  return 0;
}
