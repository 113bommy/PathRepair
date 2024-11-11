#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 5000100;
int L[M], R[M], v[M], cnt;
int root, rootL[N], rootR[N], a[N];
int build(int i, int j) {
  int novo = cnt++;
  if (i == j) return novo;
  int mid = (i + j) / 2;
  L[novo] = build(i, mid);
  R[novo] = build(mid + 1, j);
  return novo;
}
int query(int at, int i, int j, int a, int b) {
  if (i > b or j < a or a > b) return 0;
  if (i >= a and j <= b) return v[at];
  int mid = (i + j) / 2;
  return query(L[at], i, mid, a, b) + query(R[at], mid + 1, j, a, b);
}
int update(int at, int i, int j, int k) {
  if (i > k or j < k) return at;
  int novo = cnt++;
  if (i == j) {
    v[novo] = v[at] + 1;
    return novo;
  }
  int mid = (i + j) / 2;
  L[novo] = update(L[at], i, mid, k);
  R[novo] = update(R[at], mid + 1, j, k);
  v[novo] = v[L[novo]] + v[R[novo]];
  return novo;
}
int main(void) {
  int n;
  cin >> n;
  long long k;
  cin >> k;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  int m = b.size();
  root = build(0, m);
  rootR[n] = root;
  for (int i = n - 1; i >= 0; i--) rootR[i] = update(rootR[i + 1], 0, m, a[i]);
  rootL[0] = root;
  for (int i = 0; i < n; i++) rootL[i + 1] = update(rootL[i], 0, m, a[i]);
  long long total = 0;
  for (int i = 1; i <= n; i++) total += query(rootL[i], 0, m, a[i - 1] + 1, m);
  long long ans = 0;
  int l = 1, r = 1;
  long long at = total;
  while (r + 1 < n) {
    if (at <= k) {
      if (l == r) {
        l++;
        r++;
        ans += n - r;
        continue;
      }
      ans += n - r;
      at += query(rootL[l], 0, m, a[l] + 1, m);
      at += query(rootR[r], 0, m, 0, a[l] - 1);
      l++;
    } else {
      at -= query(rootL[l], 0, m, a[r] + 1, m);
      at -= query(rootR[r], 0, m, 0, a[r] - 1);
      r++;
    }
  }
  while (at <= k and l + 1 < n) {
    ans++;
    at += query(rootL[l], 0, m, a[l] + 1, m);
    at += query(rootR[r], 0, m, 0, a[l] - 1);
    l++;
  }
  if (total <= k) ans += n - 1;
  cout << ans << endl;
  return 0;
}
