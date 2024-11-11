#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int q;
vector<int> A;
vector<int> B;
vector<int> v;
int mp[201002 / 310][1 << 14];
int zz = 0;
struct BLOCK {
  vector<int> id;
  vector<int> num;
  vector<int> vv;
  vector<int> v2;
  vector<int> belong;
  vector<bool> star;
  void init() {
    int sz = vv.size() / 310;
    num.assign(sz, 0);
    id.assign(sz, -1);
    belong.assign(vv.size(), -1);
    star.assign(vv.size(), false);
    for (int i = 0; i < vv.size(); i++) {
      belong[i] = i / 310;
      belong[i] = min(belong[i], sz - 1);
      if (belong[i] == i / 310 && i % 310 == 0) {
        star[i] = true;
      }
    }
    for (int j = 0; j < id.size(); j++) id[j] = zz++;
    for (int i = 0; i < vv.size(); i++) {
      if (i) vv[i] ^= vv[i - 1];
      if (id.size()) mp[id[belong[i]]][vv[i]]++;
    }
  }
  void push_back(int b) {
    vv.push_back(b);
    v2.push_back(b);
  }
  void chang(int i, int x) {
    v2[i] ^= x;
    while (star[i] == false && i < vv.size()) {
      if (id.size()) mp[id[belong[i]]][vv[i]]--;
      vv[i] ^= x;
      if (id.size()) mp[id[belong[i]]][vv[i]]++;
      i++;
    }
    if (i < vv.size()) {
      int F = belong[i];
      while (F < num.size()) {
        num[F] ^= x;
        F++;
      }
    }
  }
  int query1() {
    int im = 0;
    int cn = 0;
    for (int i = 0; i < v2.size(); i++) {
      im ^= v2[i];
      if (im) {
        cn++;
      }
    }
    return cn;
  }
  int query() {
    if (id.size() == 0) {
      return query1();
    }
    int i = 0;
    int cnt = 0;
    while (i < num.size()) {
      cnt += mp[id[i]][num[i]];
      i++;
    }
    return vv.size() - cnt;
  }
};
struct st {
  BLOCK vv;
  int gross;
  st() { gross = 0; }
  void init() {
    for (int i = 0; i < vv.vv.size(); i++) {
      gross ^= vv.vv[i];
    }
    vv.init();
  }
  void chang(int a, int b) {
    gross ^= vv.v2[a];
    gross ^= b;
    vv.chang(a, vv.v2[a] ^ b);
  }
  int ng() { return (gross != 0); }
  int query() { return vv.query(); }
};
st b[201002];
char buf[3];
int main() {
  cin >> n >> k >> q;
  A.push_back(0);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    A.push_back(a);
  }
  B.push_back(0);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    B.push_back(a);
  }
  A.push_back(0);
  B.push_back(0);
  for (int i = 0; i < A.size(); i++) {
    v.push_back(A[i] ^ B[i]);
  }
  for (int i = 0; i + 1 < v.size(); i++) {
    b[i % k].vv.push_back(v[i] ^ v[i + 1]);
  }
  int ans = 0;
  int ng = 0;
  for (int i = 0; i < k; i++) {
    b[i].init();
    ans += b[i].query();
    ng += b[i].ng();
  }
  if (ng) {
    puts("-1");
  } else {
    printf("%d\n", ans);
  }
  while (q--) {
    scanf("%s", buf);
    int a, d;
    scanf("%d%d", &a, &d);
    if (buf[0] == 'a') {
      A[a] = d;
    } else {
      B[a] = d;
    }
    v[a] = A[a] ^ B[a];
    int i = a % k;
    ans -= b[i].query();
    if (k > 1) ans -= b[(a - 1) % k].query();
    ng -= b[i].ng();
    if (k > 1) ng -= b[(a - 1) % k].ng();
    b[i].chang(a / k, v[a] ^ v[a + 1]);
    b[(a - 1) % k].chang((a - 1) / k, v[a - 1] ^ v[a]);
    ans += b[i].query();
    ng += b[i].ng();
    if (k > 1) {
      ng += b[(a - 1) % k].ng();
      ans += b[(a - 1) % k].query();
    }
    if (ng) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}
