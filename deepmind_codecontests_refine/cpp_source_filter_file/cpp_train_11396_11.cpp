#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream &operator<<(ostream &out, pair<S, T> const &p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> const &v) {
  int l = v.size();
  for (int i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char *name, T &&arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename T, typename... Args>
void trace(const char *names, T &&arg1, Args &&...args) {
  const char *comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
struct query {
  int le, ri, val;
};
const long long size = 100200;
const long long treesize = 4 * size;
long long n, m;
vector<query> v(size);
vector<long long> sum(size), ans(size), tree(treesize);
long long build(long long l, long long r, long long index) {
  if (l == r) {
    tree[index] = ans[l];
    return tree[index];
  }
  long long mid = l + (r - l) / 2;
  return tree[index] =
             build(l, mid, 2 * index + 1) & build(mid + 1, r, 2 * index + 2);
}
long long query(long long qs, long long qe, long long s, long long e,
                long long index) {
  if (qs > e || qe < s) return (1LL << 30) - 1;
  if (qs <= s && qe >= e) return tree[index];
  long long mid = s + (e - s) / 2;
  return query(qs, qe, s, mid, 2 * index + 1) &
         query(qs, qe, mid + 1, e, 2 * index + 2);
}
int main() {
  clock_t tStart = clock();
  int test;
  test = 1;
  while (test--) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      cin >> v[i].le >> v[i].ri >> v[i].val;
      v[i].le--;
    }
    for (int i = 0; i < size; i++) {
      ans[i] = 0;
    }
    for (int i = 0; i <= 30; i++) {
      for (int j = 0; j < size; j++) {
        sum[j] = 0;
      }
      for (int j = 0; j < m; j++) {
        if (v[j].val & (1 << i)) {
          sum[v[j].le]++;
          sum[v[j].ri]--;
        }
      }
      for (int j = 0; j < n; j++) {
        if (j > 0) sum[j] += sum[j - 1];
        if (sum[j] > 0) {
          ans[j] |= (1 << i);
        }
      }
    }
    build(0, n - 1, 0);
    bool f = 0;
    for (int i = 0; i < m; i++) {
      if (query(v[i].le, v[i].ri, 0, n - 1, 0) != v[i].val) {
        f = 1;
        break;
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
      }
      cout << "\n";
    }
  }
  return 0;
}
