#include <bits/stdc++.h>
using namespace std;
const int N = 300004;
int l[N], r[N];
pair<int, pair<int, int> > arr[N];
int bit[4 * N];
map<int, int> mp;
vector<int> vec;
void update(int x, int val) {
  while (x < 4 * N) {
    bit[x] += val;
    x += x & -x;
  }
}
int query(int x) {
  int ans = 0;
  while (x > 0) {
    ans += bit[x];
    x -= x & -x;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d %d", &l[i], &r[i]);
    if (!mp[l[i]]) {
      mp[l[i]] = 1;
      vec.push_back(l[i]);
    }
    if (!mp[l[i] - 1]) {
      mp[l[i] - 1] = 1;
      vec.push_back(l[i] - 1);
    }
    if (!mp[r[i]]) {
      mp[r[i]] = 1;
      vec.push_back(r[i]);
    }
  }
  sort(vec.begin(), vec.end());
  for (i = 0; i < vec.size(); i++) mp[vec[i]] = i + 1;
  for (i = 1; i <= n; i++) {
    l[i] = mp[l[i]];
    r[i] = mp[r[i]];
    arr[i] = make_pair(l[i], make_pair(-r[i], i));
  }
  sort(arr + 1, arr + n + 1);
  for (i = n; i >= 1; i--) {
    int q = query(-arr[i].second.first) - query(arr[i].first - 1);
    if (q > 0) {
      for (int j = i + 1; j <= n; j++) {
        if (arr[j].first >= arr[i].first &&
            (-arr[j].second.first) <= (-arr[i].second.first)) {
          printf("%d %d\n", arr[j].second.second, arr[i].second.second);
          return 0;
        }
      }
    }
    update(-arr[i].second.first, 1);
  }
  printf("-1 -1\n");
  return 0;
}
