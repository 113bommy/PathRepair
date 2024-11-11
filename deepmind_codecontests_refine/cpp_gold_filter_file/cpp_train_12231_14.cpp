#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long linf = 1e18;
const int inf = 1e9;
const int N = 1e6 + 5;
int a[N], i, j, k, n, m, x, y;
map<int, vector<int> > v;
long long F[N], ans[N];
long long query(int x, int y) {
  long long sum = 0;
  x--;
  for (; y > 0; y -= y & -y) sum += F[y];
  for (; x > 0; x -= x & -x) sum -= F[x];
  return sum;
}
void update(int x, int y) {
  for (; x && x < N; x += x & -x) F[x] += y;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    v[a[i]].push_back(i);
  }
  for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++) {
    for (__typeof(it->second.begin()) it2 = it->second.begin();
         it2 != it->second.end(); it2++) {
      int temp = *it2;
      for (int k = 1; k * (temp - 1) + 2 <= n && k <= n - 1; k++)
        ans[k] += query(k * (temp - 1) + 2, k * temp + 1);
    }
    for (__typeof(it->second.begin()) it2 = it->second.begin();
         it2 != it->second.end(); it2++)
      update(*it2, 1);
  }
  for (int i = 1; i <= n - 1; i++) cout << ans[i] << " \n"[i == n - 1];
  return 0;
}
