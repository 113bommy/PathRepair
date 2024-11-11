#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> tree(1e6 * 3);
vector<long long> books;
long long k, sz;
long long maximum = 0;
vector<pair<long long, long long>> res;
void build(long long start, long long end, long long index) {
  if (start == end) {
    tree[index] = make_pair(books[start], books[end]);
  } else {
    build(start, (start + end) / 2, index * 2);
    build((start + end) / 2 + 1, end, index * 2 + 1);
    tree[index].first = max(tree[index * 2].first, tree[index * 2 + 1].first);
    tree[index].second =
        min(tree[index * 2].second, tree[index * 2 + 1].second);
  }
}
pair<long long, long long> get_deff(long long start, long long end,
                                    long long right, long long left,
                                    long long index) {
  if (end < left || start > right) {
    return make_pair(-1, 1e9);
  }
  if (start >= left && end <= right) {
    return tree[index];
  }
  pair<long long, long long> f, s;
  f = get_deff(start, (end + start) / 2, right, left, 2 * index);
  s = get_deff((end + start) / 2 + 1, end, right, left, 2 * index + 1);
  return make_pair(max(f.first, s.first), min(f.second, s.second));
}
bool valid(long long in) {
  for (long long i = 0; i < (long long)books.size() - in + 1; i++) {
    pair<long long, long long> minmax = get_deff(0, sz - 1, i + in - 1, i, 1);
    long long deff = minmax.first - minmax.second;
    if (deff <= k) {
      maximum = max(maximum, in);
      return true;
    }
  }
  return false;
}
void final_func(long long in) {
  for (long long i = 0; i < (long long)books.size() - in + 1; i++) {
    pair<long long, long long> minmax = get_deff(0, sz - 1, i + in - 1, i, 1);
    if (minmax.first - minmax.second <= k) {
      res.push_back(make_pair(i + 1, i + in));
    }
  }
}
int main() {
  cin >> sz >> k;
  books.resize(sz);
  for (long long i = 0; i < sz; i++) {
    scanf("%lld", &books[i]);
  }
  build(0, sz - 1, 1);
  long long mn = 1, mx = 1e5 + 1, mid;
  while (mx - mn != 1) {
    mid = (mx + mn) / 2;
    if (valid(mid)) {
      mn = mid;
    } else {
      mx = mid;
    }
  }
  if (valid(mx)) {
    final_func(mx);
  } else {
    final_func(mn);
  }
  cout << maximum << " " << res.size() << endl;
  for (long long i = 0; i < res.size(); i++) {
    printf("%lld %lld\n", res[i].first, res[i].second);
  }
  return 0;
}
