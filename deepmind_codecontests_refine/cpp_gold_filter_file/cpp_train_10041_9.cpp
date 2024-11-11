#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int freen[100010];
vector<int> V[100010];
int id[100010];
bool cmp(int A, int B) { return (int)V[A].size() > (int)V[B].size(); }
int lowbit(int t) { return t & (t ^ (t - 1)); }
int in[10010][2];
int sum(int end, int ss) {
  int sum = 0;
  while (end > 0) {
    sum += in[end][ss];
    end -= lowbit(end);
  }
  return sum;
}
void add(int pos, int num, int ss) {
  while (pos <= 10000) {
    in[pos][ss] += num;
    pos += lowbit(pos);
  }
}
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    a[i]++;
    if (a[i] == 1) {
    } else {
      ans += b[i];
    }
    V[a[i]].push_back(b[i]);
    freen[a[i]] = 0;
  }
  if (n == 1) {
    if (a[1] == 1) {
      cout << 0 << endl;
    } else {
      cout << b[1] << endl;
    }
    return 0;
  }
  for (int i = 2; i <= 100001; i++) {
    id[i] = i;
    sort(V[i].begin(), V[i].end());
  }
  sort(id + 2, id + 1 + 100001, cmp);
  int cnt = n;
  int tot = ans;
  for (int i = 1; i <= n; i++) {
    int tmp = 0;
    for (int j = 2; j <= 100001; j++) {
      int u = id[j];
      int sz = (int)V[u].size();
      if (freen[u] < i && freen[u] < sz) {
        freen[u]++;
        cnt--;
        tot -= V[u][sz - freen[u]];
        if (V[u][sz - freen[u]] == 0) {
          cnt++;
        } else {
          add(V[u][sz - freen[u]], 1, 0);
          add(V[u][sz - freen[u]], V[u][sz - freen[u]], 1);
        }
      } else {
        break;
      }
    }
    if (cnt + sum(10000, 0) <= i) {
      continue;
    }
    if (cnt > i) {
      ans = min(ans, tot);
      continue;
    }
    int l, r, mid;
    l = 1, r = 10000;
    while (l < r) {
      mid = (l + r) >> 1;
      if (sum(mid, 0) + cnt > i) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    tmp = sum(r, 1);
    tmp -= r * (sum(r, 0) + cnt - i - 1);
    ans = min(ans, tmp + tot);
  }
  cout << ans << endl;
  return 0;
}
