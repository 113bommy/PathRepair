#include <bits/stdc++.h>
using namespace std;
inline long long start_diff(int k) { return 1ll * k * (k - 1) / 2; }
pair<int, int> gen_bucket(long long diff, int k) {
  int cnt = (diff - 1) / k;
  diff -= 1ll * cnt * k;
  return make_pair(cnt, k - (diff - 1));
}
vector<int> gen_bucket_old(long long diff, int k) {
  int cnt = (diff - 1) / k;
  diff -= 1ll * cnt * k;
  vector<int> res(cnt, 0);
  res.push_back(k - (diff - 1));
  res.push_back(diff - 1);
  for (int i = 0; i < k - cnt - 2; ++i) {
    res.push_back(0);
  }
  return res;
}
int get_inner_diff(pair<int, int> bucket, int pos, int k) {
  int cnt, add;
  tie(cnt, add) = bucket;
  if (pos <= cnt) {
    return -pos;
  } else if (pos == cnt + 1) {
    return add - pos;
  } else {
    return k - pos;
  }
}
long long get_total_sums(pair<int, int> bucket, long long bid, long long bpos,
                         int k) {
  int cnt, add;
  tie(cnt, add) = bucket;
  long long len = 1ll * k * k;
  int pos = bpos / (len + 1);
  long long spos = bpos % (len + 1);
  long long bad_pos = start_diff(k) - 1 + get_inner_diff(bucket, pos, k);
  if (spos == bad_pos) {
    return -1ll;
  }
  long long total_sums = 1 + bid * k * k + 1ll * k * pos;
  if (spos > bad_pos) {
    total_sums += (spos - 1) / k;
  } else {
    total_sums += spos / k;
  }
  long long total_buckets = bid * k + pos;
  if (spos > bad_pos) {
    total_buckets++;
  }
  return total_sums - total_buckets;
}
pair<int, int> gen_bucket_rec(long long bid, int k) {
  if (bid == 0) {
    return gen_bucket(start_diff(k), k);
  } else {
    long long par_bid = bid / k;
    int inn_id = bid % k;
    auto bpar = gen_bucket_rec(par_bid, k);
    long long inner_start_diff =
        start_diff(k) + get_inner_diff(bpar, inn_id, k);
    return gen_bucket(inner_start_diff, k);
  }
}
long long find_gen(long long n, int k) {
  n -= 1ll * k * (k - 1) / 2;
  return n / k;
}
long long solve(long long n, int k) {
  if (n <= k) return n;
  long long diff = 1ll * k * (k - 1) / 2;
  long long blen = (1ll * k * k + 1) * k;
  long long bid = (n - k - 1) / blen, bpos = (n - k - 1) % blen;
  auto bucket = gen_bucket_rec(bid, k);
  long long total_sums = get_total_sums(bucket, bid, bpos, k);
  if (total_sums != -1) {
    return n + total_sums;
  } else {
    return solve(find_gen(n, k), k) + k;
  }
  for (auto x : gen_bucket_old(diff, k)) {
    cerr << x + k * k << ' ';
  }
  cerr << endl;
  for (int i = 0; i < k; ++i) {
    cerr << start_diff(k) + get_inner_diff(gen_bucket(start_diff(k), k), i, k)
         << ' ';
  }
  cerr << endl;
  return 0;
}
long long solve_naive(long long n, int k) {
  vector<long long> used;
  int p = 0;
  int res = 0;
  for (int i = 1;;) {
    long long sum = 0ll;
    for (int _ = 0; _ < k; ++_) {
      while (p < used.size() && used[p] == i) {
        ++i;
        ++p;
      }
      sum += i;
      res++;
      if (n == i) return res;
      ++i;
    }
    used.push_back(sum);
    res++;
    if (sum == n) return res;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int k;
    long long n;
    cin >> n >> k;
    cout << solve(n, k) << '\n';
  }
  return 0;
}
