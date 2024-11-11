#include <bits/stdc++.h>
using namespace std;
struct data {
  long long ty, ti, val, id;
} DATA[100010];
vector<long long> V[100010];
map<long long, long long> m;
long long ans[100010], ck[100010];
pair<long long, long long> arr[100010];
long long n;
long long tree[100010], a[100010];
void update(long long idx, long long x, long long n1) {
  while (idx <= n1) {
    tree[idx] += x;
    idx += idx & (-idx);
  }
}
long long query(long long idx) {
  long long sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= idx & (-idx);
  }
  return sum;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  long long ind = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> DATA[i].ty >> DATA[i].ti >> DATA[i].val;
    DATA[i].id = i;
    if (!m.count(DATA[i].val)) m[DATA[i].val] = ind, ind++;
    DATA[i].val = m[DATA[i].val];
    arr[i] = make_pair(DATA[i].ti, DATA[i].id);
  }
  sort(arr + 1, arr + n + 1);
  for (long long i = 1; i <= n; i++) {
    long long sz = ck[DATA[arr[i].second].val];
    DATA[arr[i].second].ti = sz + 1;
    ck[DATA[arr[i].second].val]++;
  }
  for (long long i = 1; i <= n; i++) V[DATA[i].val].push_back(i);
  for (long long i = 1; i < ind; i++) {
    for (long long j = 1; j <= V[i].size(); j++) tree[j] = 0;
    long long sz = V[i].size();
    for (auto it : V[i]) {
      if (DATA[it].ty == 1)
        update(DATA[it].ti, 1, sz);
      else if (DATA[it].ty == 2)
        update(DATA[it].ti, -1, sz);
      else {
        long long p = query(DATA[it].ti);
        ans[DATA[it].id] = p;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (DATA[i].ty == 3) cout << ans[DATA[i].id] << endl;
  }
}
