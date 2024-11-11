#include <bits/stdc++.h>
struct query {
  int l;
  int r;
  int idx;
  int tot;
  int64_t res;
  query(int left, int right, int index, int total)
      : l(left), r(right), idx(index), tot(total) {
    res = 0;
  }
};
bool sort_fun(query &i, query &j) {
  int bi = (int)(i.l / (int)std::sqrt(i.tot));
  int bj = (int)(j.l / (int)std::sqrt(j.tot));
  if (bi == bj) {
    return i.r < j.r;
  } else {
    return bi < bj;
  }
}
bool sort_fun1(query i, query j) { return i.idx < j.idx; }
void solve(std::vector<int> const &a, std::vector<query> &q,
           std::vector<int64_t> const &values, int s, int e) {
  int curri = q[s].l;
  int currj = q[s].l - 1;
  std::vector<uint64_t> occ(a.size(), 0);
  int64_t answer = 0;
  for (int i = s; i < e; ++i) {
    while (curri < q[i].l) {
      answer -= occ[a[curri]] * occ[a[curri]] * values[a[curri]];
      occ[a[curri]]--;
      answer += occ[a[curri]] * occ[a[curri]] * values[a[curri]];
      curri++;
    }
    while (curri > q[i].l) {
      --curri;
      answer -= occ[a[curri]] * occ[a[curri]] * values[a[curri]];
      occ[a[curri]]++;
      answer += occ[a[curri]] * occ[a[curri]] * values[a[curri]];
    }
    while (currj < q[i].r) {
      ++currj;
      answer -= occ[a[currj]] * occ[a[currj]] * values[a[currj]];
      occ[a[currj]]++;
      answer += occ[a[currj]] * occ[a[currj]] * values[a[currj]];
    }
    while (currj > q[i].r) {
      answer -= occ[a[currj]] * occ[a[currj]] * values[a[currj]];
      occ[a[currj]]--;
      answer += occ[a[currj]] * occ[a[currj]] * values[a[currj]];
      --currj;
    }
    q[i].res = answer;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  int n, q;
  std::cin >> n >> q;
  std::vector<int64_t> array;
  std::vector<int64_t> remap;
  std::vector<int> pos;
  std::vector<query> queries;
  array.reserve(n);
  remap.reserve(n);
  pos.reserve(n);
  for (int i = 0; i < n; ++i) {
    int64_t tmp;
    std::cin >> tmp;
    array.push_back(tmp);
    remap.push_back(tmp);
  }
  std::sort(remap.begin(), remap.end());
  for (int i = 0; i < n; ++i) {
    auto pp = std::lower_bound(remap.begin(), remap.end(), array[i]);
    int p = (pp - remap.begin());
    pos.push_back(p);
  }
  for (int i = 0; i < q; ++i) {
    int tmpl, tmpr;
    std::cin >> tmpl >> tmpr;
    queries.push_back(query(tmpl - 1, tmpr - 1, i, n));
  }
  std::sort(queries.begin(), queries.end(), sort_fun);
  int start = 0;
  int end = 0;
  int idx = 0;
  while (end < q) {
    idx += (int)sqrt(n);
    while (queries[end].l < idx && end < q) {
      end++;
    }
    solve(pos, queries, remap, start, end);
    start = end;
  }
  std::sort(queries.begin(), queries.end(), sort_fun1);
  for (auto &q : queries) {
    std::cout << q.res << std::endl;
  }
}
