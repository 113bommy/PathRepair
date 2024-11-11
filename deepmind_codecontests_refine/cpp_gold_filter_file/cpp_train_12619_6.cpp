#include <bits/stdc++.h>
using namespace std;
long long A[100005], tree[4 * 100005];
long long power(long long x, long long p) {
  if (p == 0) return 1;
  long long y = power(x, p / 2);
  y *= y;
  y %= 1000000007;
  if (p % 2 == 0) return y;
  y *= x;
  y %= 1000000007;
  return y;
}
bool prime[10000001];
void sieveFunction(long long maxLimit) {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (long long i = 2; i <= maxLimit; i++) {
    if (prime[i]) {
      for (long long j = 2 * i; j < maxLimit; j += i) prime[j] = false;
    }
  }
}
void build(long long node, long long start, long long end) {
  if (start == end)
    tree[node] = A[start];
  else {
    long long mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}
void update(long long node, long long start, long long end, long long idx,
            long long val) {
  if (start == end) {
    A[idx] = val;
    tree[node] += val;
  } else {
    long long mid = (start - end) / 2 + end;
    if (start <= idx && idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}
long long query(long long node, long long start, long long end, long long l,
                long long r) {
  if (r < start || l > end) {
    return 0;
  }
  if (l <= start && end <= r) {
    return tree[node];
  }
  long long mid = (start + end) / 2;
  long long p1 = query(2 * node, start, mid, l, r);
  long long p2 = query(2 * node + 1, mid + 1, end, l, r);
  return p1 + p2;
}
long long maxSubArraySum(long long a[], long long start, long long end) {
  long long max_so_far = 0, max_ending_here = 0;
  for (long long i = start; i < end; i++) {
    max_ending_here = max_ending_here + a[i];
    if (max_ending_here < 0)
      max_ending_here = 0;
    else if (max_so_far < max_ending_here)
      max_so_far = max_ending_here;
  }
  return max_so_far;
}
signed main() {
  ios_base::sync_with_stdio(false);
  long long n, q;
  cin >> n >> q;
  long long a[3][n + 1];
  for (long long i = 1; i < 3; i++)
    for (long long j = 1; j <= n; j++) a[i][j] = 0;
  long long block = 0;
  while (q--) {
    long long x, y;
    cin >> x >> y;
    if (x == 1) {
      if (y == n) {
        if (a[x][y] == 0) {
          if (a[x + 1][y - 1] == 1) block++;
        } else {
          if (a[x + 1][y - 1] == 1) block--;
        }
      } else {
        if (a[x][y] == 0) {
          if (a[x + 1][y - 1] == 1) block++;
          if (a[x + 1][y + 1] == 1) block++;
          if (a[x + 1][y] == 1) block++;
        } else {
          if (a[x + 1][y - 1] == 1) block--;
          if (a[x + 1][y + 1] == 1) block--;
          if (a[x + 1][y] == 1) block--;
        }
      }
    } else {
      if (y == 1) {
        if (a[x][y] == 0) {
          if (a[x - 1][y + 1] == 1) block++;
        } else {
          if (a[x - 1][y + 1] == 1) block--;
        }
      } else {
        if (a[x][y] == 0) {
          if (a[x - 1][y - 1] == 1) block++;
          if (a[x - 1][y + 1] == 1) block++;
          if (a[x - 1][y] == 1) block++;
        } else {
          if (a[x - 1][y - 1] == 1) block--;
          if (a[x - 1][y + 1] == 1) block--;
          if (a[x - 1][y] == 1) block--;
        }
      }
    }
    a[x][y] = !a[x][y];
    if (block == 0)
      cout << "yes" << endl;
    else {
      cout << "no" << endl;
    }
  }
}
