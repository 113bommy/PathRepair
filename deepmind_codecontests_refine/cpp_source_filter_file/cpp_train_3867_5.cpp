#include <bits/stdc++.h>
using namespace std;
const int max_n = 400000;
int m = 1000000000 + 7;
int val[4 * max_n];
unsigned long long pmask[4 * max_n];
unsigned long long updmask[4 * max_n];
int updval[4 * max_n];
vector<int> primes;
vector<int> reversed;
int mul(int a, int b) { return (int)(((unsigned long long)a * b) % m); }
int add(int a, int b) { return (int)(((unsigned long long)a + b) % m); }
int fpow(int a, int n, int res = 1) {
  while (n) {
    if (n % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    n /= 2;
  }
  return res;
}
void make_tree(int id, int l, int r, vector<int> &a) {
  updval[id] = 1;
  if (l == r - 1) {
    val[id] = a[l];
    for (int i = 0; i < primes.size(); ++i) {
      if (a[l] % primes[i] == 0) {
        pmask[id] |= 1ULL << i;
      }
    }
  } else {
    int mid = (l + r) / 2;
    make_tree(2 * id + 1, l, mid, a);
    make_tree(2 * id + 2, mid, r, a);
    val[id] = mul(val[2 * id + 1], val[2 * id + 2]);
    pmask[id] = pmask[2 * id + 1] | pmask[2 * id + 2];
  }
}
void update(int id, int l, int r) {
  if (updval[id] != 1) {
    val[id] = fpow(updval[id], r - l, val[id]);
  }
  pmask[id] |= updmask[id];
  if (l != r - 1) {
    updval[2 * id + 1] = mul(updval[2 * id + 1], updval[id]);
    updval[2 * id + 2] = mul(updval[2 * id + 2], updval[id]);
    updmask[2 * id + 1] |= updmask[id];
    updmask[2 * id + 2] |= updmask[id];
  }
  updval[id] = 1;
  updmask[id] = 0;
}
pair<int, unsigned long long> get_val(int id, int l, int r, int constl,
                                      int constr) {
  if (r <= constl || l >= constr) {
    return pair<int, unsigned long long>(1, 0);
  }
  update(id, l, r);
  if (l >= constl && r <= constr) {
    return pair<int, unsigned long long>(val[id], pmask[id]);
  }
  int mid = (l + r) / 2;
  auto c1 = get_val(2 * id + 1, l, mid, constl, constr);
  auto c2 = get_val(2 * id + 2, mid, r, constl, constr);
  return pair<int, unsigned long long>(mul(c1.first, c2.first),
                                       c1.second | c2.second);
}
void multiply(int id, int l, int r, int constl, int constr, int x,
              unsigned long long msk) {
  if (l >= constr || r <= constl) {
    return;
  }
  update(id, l, r);
  if (l >= constl && r <= constr) {
    updval[id] = x;
    updmask[id] = msk;
    return;
  }
  int mid = (l + r) / 2;
  multiply(2 * id + 1, l, mid, constl, constr, x, msk);
  multiply(2 * id + 2, mid, r, constl, constr, x, msk);
  val[id] = fpow(x, min(r, constr) - max(l, constl), val[id]);
  pmask[id] |= msk;
}
int main() {
  for (int i = 2; i <= 300; ++i) {
    bool found = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        found = false;
        break;
      }
    }
    if (found) {
      primes.push_back(i);
      reversed.push_back(fpow(i, m - 2));
    }
  }
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  make_tree(0, 0, n, a);
  for (int i = 0; i < q; ++i) {
    string qu;
    cin >> qu;
    if (qu == "TOTIENT") {
      int l, r;
      cin >> l >> r;
      pair<int, unsigned long long> res = get_val(0, 0, n, l - 1, r);
      for (int j = 0; j < primes.size(); ++j) {
        if ((res.second >> j) & 1) {
          res.first = mul(mul(res.first, primes[j] - 1), reversed[j]);
        }
      }
      cout << res.first << endl;
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      unsigned long long msk = 0;
      for (int j = 0; j < primes.size(); ++j) {
        if (x % primes[j] == 0) {
          msk |= 1UL << j;
        }
      }
      multiply(0, 0, n, l - 1, r, x, msk);
    }
  }
  return 0;
}
