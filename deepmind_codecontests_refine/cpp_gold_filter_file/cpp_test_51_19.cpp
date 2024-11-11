#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e10;
struct evnt {
  long long p;
  bool l;
};
struct tarif {
  long long l, r, c, p;
};
struct tree {
  vector<long long> tr_cpu;
  vector<long long> add;
  vector<long long> tr_price;
  long long e;
  tree(long long sz) {
    tr_cpu.resize(sz * 4);
    tr_price.resize(sz * 4);
    add.resize(sz * 4);
    e = sz;
  }
  void push(long long v, long long l, long long r) {
    tr_cpu[v] += add[v];
    if (l != r) {
      add[v * 2] += add[v];
      add[v * 2 + 1] += add[v];
    }
    add[v] = 0;
  }
  long long add1, modN, l, r, pos;
  void MOD(long long v, long long num1, long long num2, long long v1) {
    l = v, r = e - 1, pos = v1, modN = num2, add1 = num1;
    modify_cpu(1, 0, e - 1);
    modify_price(1, 0, e - 1);
  }
  void modify_cpu(long long v, long long l1, long long r1) {
    if (l <= l1 && r1 <= r) {
      add[v] += add1;
      push(v, l1, r1);
      return;
    }
    if (l > r1 || r < l1) return;
    push(v, l1, r1);
    modify_cpu(v * 2, l1, (l1 + r1) / 2);
    modify_cpu(v * 2 + 1, (l1 + r1) / 2 + 1, r1);
    tr_cpu[v] = tr_cpu[2 * v] + tr_cpu[2 * v + 1];
  }
  void modify_price(long long v, long long l1, long long r1) {
    if (pos < l1 || pos > r1) return;
    if (l1 == r1)
      tr_price[v] = modN;
    else {
      modify_price(v * 2, l1, (l1 + r1) / 2);
      modify_price(v * 2 + 1, 1 + (l1 + r1) / 2, r1);
    }
  }
  long long serch_result;
  pair<long long, long long> search(long long v, long long l1, long long r1,
                                    long long o) {
    if (l1 == r1) {
      serch_result = o;
      return {0, l1};
    }
    if (tr_cpu[v * 2] >= o)
      return search(v * 2, l1, (l1 + r1) / 2, o);
    else {
      auto [v1, rs] =
          search(v * 2 + 1, (l1 + r1) / 2 + 1, r1, o - tr_cpu[v * 2]);
      return {v1, rs + tr_cpu[v * 2]};
    }
  }
};
int main() {
  long long a;
  cin >> a;
  while (a--) {
    long long k;
    cin >> k;
    cout << -k + 1 << ' ' << k << '\n';
  }
}
