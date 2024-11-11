#include <bits/stdc++.h>
using namespace std;
long long a[200006];
vector<int> pos[200006];
map<long long, int> m;
int idx;
int getidx(long long num) {
  map<long long, int>::iterator iter = m.find(num);
  if (iter == m.end()) {
    m[num] = idx;
    idx++;
    return idx - 1;
  }
  return iter->second;
}
int getidx2(int num) {
  map<long long, int>::iterator iter = m.find(num);
  if (iter == m.end()) {
    return -1;
  }
  return iter->second;
}
long long countbefore(int idx, int target) {
  vector<int>::iterator iter =
      lower_bound(pos[idx].begin(), pos[idx].end(), target);
  return iter - pos[idx].begin();
}
long long countafter(int idx, int target) {
  vector<int>::iterator iter =
      upper_bound(pos[idx].begin(), pos[idx].end(), target);
  return pos[idx].end() - iter;
}
int main() {
  idx = 0;
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    int aidx = getidx(a[i]);
    pos[aidx].push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % k == 0) {
      int beforeidx = getidx2(a[i] / k);
      int afteridx = getidx2(a[i] * k);
      if (beforeidx != -1 && afteridx != -1) {
        long long beforecnt = countbefore(beforeidx, i);
        long long aftercnt = countafter(afteridx, i);
        ans += beforecnt * aftercnt;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
