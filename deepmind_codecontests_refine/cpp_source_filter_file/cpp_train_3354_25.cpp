#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 3e5 + 10;
const long long MAX = 3e5 + 10;
long long gcd(long long n, long long m) {
  if (n == 0)
    return m;
  else
    return gcd(m % n, n);
}
struct Query {
  long long l, r, idx;
};
bool cmp(Query x, Query y) { return x.r < y.r; }
void update(long long idx, long long val, long long bit[], long long n) {
  for (; idx <= n; idx += idx & -idx) bit[idx] += val;
}
long long query(long long idx, long long bit[], long long n) {
  long long sum = 0;
  for (; idx > 0; idx -= idx & -idx) sum += bit[idx];
  return sum;
}
long long ans[N];
void answeringQueries(long long arr[], long long n, Query queries[],
                      long long q) {
  long long bit[n + 1];
  memset(bit, 0, sizeof(bit));
  long long last_visit[MAX];
  memset(last_visit, -1, sizeof(last_visit));
  long long query_counter = 0;
  for (long long i = 0; i < n; i++) {
    if (last_visit[arr[i]] != -1) update(last_visit[arr[i]] + 1, -1, bit, n);
    last_visit[arr[i]] = i;
    update(i + 1, 1, bit, n);
    while (query_counter < q && queries[query_counter].r == i) {
      ans[queries[query_counter].idx] =
          query(queries[query_counter].r + 1, bit, n) -
          query(queries[query_counter].l, bit, n);
      query_counter++;
    }
  }
}
long long a[N], mp[N], pre[N], mx[N], mn[N];
long long bit[N];
void update2(long long idx) {
  while (idx <= 3e5 + 2) {
    bit[idx] += 1;
    idx += idx & -idx;
  }
}
long long getsum(long long idx) {
  long long sum = 0;
  while (idx > 0) {
    sum += bit[idx];
    idx -= idx & -idx;
  }
  return sum;
}
vector<long long> vp[N];
Query queries[N];
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    cin >> a[i];
    mp[a[i]]++;
    vp[a[i]].push_back(i);
  }
  for (long long i = 1; i <= n; i++) {
    if (mp[i] > 0) {
      mn[i] = 1;
    }
  }
  for (long long i = n; i >= 1; i--) {
    if (mp[i] > 0) {
      pre[i] = pre[i + 1] + 1;
    } else
      pre[i] = pre[i + 1];
  }
  for (long long i = 1; i <= n; i++) {
    if (mp[i] == 0) {
      mn[i] = i;
      mx[i] = i + pre[i];
    } else
      mx[i] = i;
  }
  map<long long, long long> m1;
  long long sum = 0;
  for (long long i = 0; i < m; i++) {
    if (m1[a[i]] == 0) {
      long long k1 = getsum(a[i]);
      mx[a[i]] += sum - k1;
      m1[a[i]]++;
      sum++;
      update2(a[i]);
    }
  }
  m1.clear();
  long long cnt = 0;
  for (long long i = 0; i < m; i++) {
    if (m1[a[i]] == 0) {
      long long k = a[i];
      for (long long j = 1; j < vp[k].size(); j++) {
        long long p = vp[k][j - 1];
        long long p1 = vp[k][j];
        if (p1 - p1 >= 1) {
          queries[cnt].l = p + 1;
          queries[cnt].r = p1 - 1;
          queries[cnt].idx = cnt;
          cnt++;
        }
      }
      if (a[m - 1] != k) {
        long long z = vp[k][vp[k].size() - 1];
        if (m - 1 - z >= 1) {
          queries[cnt].l = z + 1;
          queries[cnt].r = m - 1;
          queries[cnt].idx = cnt;
          cnt++;
        }
      }
      m1[a[i]]++;
    }
  }
  sort(queries, queries + cnt, cmp);
  answeringQueries(a, m, queries, cnt);
  m1.clear();
  cnt = 0;
  for (long long i = 0; i < m; i++) {
    if (m1[a[i]] == 0) {
      long long k = a[i];
      for (long long j = 1; j < vp[k].size(); j++) {
        long long p = vp[k][j - 1];
        long long p1 = vp[k][j];
        if (p1 - p >= 1) {
          mx[a[i]] = max(mx[a[i]], 1 + ans[cnt]);
          cnt++;
        }
      }
      if (a[m - 1] != k) {
        long long z = vp[k][vp[k].size() - 1];
        if (m - 1 - z >= 1) {
          mx[a[i]] = max(mx[a[i]], 1 + ans[cnt]);
          cnt++;
        }
      }
      m1[a[i]]++;
    }
  }
  for (long long i = 1; i <= n; i++) {
    cout << mn[i] << " " << mx[i] << endl;
  }
}
