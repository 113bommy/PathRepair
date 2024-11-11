#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
int l[1000005], r[1000005];
int a[6000005];
int back_ass[6000005];
int main() {
  int n, k;
  cin >> n >> k;
  set<int> border;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", l + i, r + i);
    border.insert(l[i]);
    border.insert(r[i]);
  }
  int cnt = 0;
  map<int, int> ass;
  for (set<int>::iterator it = border.begin(); it != border.end(); it++) {
    int val = *it;
    ass.insert(make_pair(val, cnt));
    back_ass[cnt] = val;
    cnt += 2;
  }
  for (int i = 0; i < n; i++) {
    int rl = ass[l[i]];
    int rr = ass[r[i]];
    a[rl]++;
    a[rr + 1]--;
  }
  cnt = 0;
  int prevl = -1;
  vector<int> ans;
  for (int i = 0; i <= 6000000; i++) {
    cnt += a[i];
    if (cnt < k && prevl != -1) {
      ans.push_back(back_ass[prevl]);
      ans.push_back(back_ass[i - 1]);
      prevl = -1;
    }
    if (cnt >= k && prevl == -1) prevl = i;
  }
  cout << (int)ans.size() / 2 << "\n";
  for (int i = 0; i < ans.size(); i += 2) {
    printf("%d %d\n", ans[i], ans[i + 1]);
  }
  return 0;
}
