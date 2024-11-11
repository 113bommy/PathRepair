#include <bits/stdc++.h>
using namespace std;
int n, m, i;
long long t[200000], ti;
int s[200000], f[200000], pl, nn, so, q, c1, c2, hh, num, need;
int ff[200000], ff2[200000];
int nu[200000], nap;
int www[200000], wwww[200000];
long long ans[200000];
vector<int> qqq[200000];
vector<int> qqqq[200000];
vector<int> eee[200000];
void up(int v, int t) {
  while (v <= m) {
    ff[v] += t;
    v = (v | (v + 1));
  }
}
int get(int v) {
  int t = 0;
  while (v > 0) {
    t += ff[v];
    v = (v & (v + 1)) - 1;
  }
  return t;
}
void up2(int v, int t) {
  while (v <= m) {
    ff2[v] += t;
    v = (v | (v + 1));
  }
}
int get2(int v) {
  int t = 0;
  while (v > 0) {
    t += ff2[v];
    v = (v & (v + 1)) - 1;
  }
  return t;
}
void sortt(int l, int r) {
  int i = l, j = r;
  long long x = t[l + (rand() * rand()) % (r - l + 1)];
  while (i <= j) {
    while (t[i] < x) i++;
    while (x < t[j]) j--;
    if (i <= j) {
      swap(t[i], t[j]);
      swap(s[i], s[j]);
      swap(f[i], f[j]);
      swap(nu[i], nu[j]);
      i++;
      j--;
    }
  }
  if (i < r) sortt(i, r);
  if (l < j) sortt(l, j);
}
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    scanf("%I64d%I64d%I64d", &t[i], &s[i], &f[i]);
    nu[i] = i + 1;
  }
  t[n] = 1000000000000000000LL;
  sortt(0, n);
  ti = 1;
  hh = n;
  i = 0;
  num = 1;
  while (hh) {
    while (t[i] == ti) {
      up2(s[i], 1);
      qqq[s[i]].push_back(f[i]);
      qqqq[s[i]].push_back(nu[i]);
      i++;
    }
    c1 = get(num) - get(num - 1);
    up(num, -c1);
    while (wwww[num] < eee[num].size()) {
      ans[eee[num][wwww[num]]] = ti;
      hh--;
      wwww[num]++;
    }
    while (www[num] < qqq[num].size()) {
      up2(num, -1);
      up(qqq[num][www[num]], 1);
      eee[qqq[num][www[num]]].push_back(qqqq[num][www[num]]);
      www[num]++;
    }
    c1 = get(m) - get(num) + get2(m) - get2(num);
    c2 = get(num - 1) + get2(num - 1);
    if (c1 >= c2)
      nap = 1;
    else
      nap = -1;
    if (nap == 1) {
      nn = num;
      so = get(num) + get2(num);
      if (c1 == 0) {
        need = 2000000000;
      } else {
        for (q = 20; q >= 0; q--) {
          pl = nn + (1 << q);
          if (pl > m) continue;
          if (get(pl) + get2(pl) != so) continue;
          nn = pl;
        }
        need = nn - num + 1;
      }
    } else {
      nn = num;
      so = get(num - 1) + get2(num - 1);
      for (q = 20; q >= 0; q--) {
        pl = nn - (1 << q);
        if (pl < 0) continue;
        if (get(pl - 1) + get2(pl - 1) != so) continue;
        nn = pl;
      }
      need = num - nn + 1;
    }
    if (need == 2000000000) {
      ti = t[i];
      continue;
    } else if (t[i] - ti >= need) {
      num = num + need * nap;
      ti = ti + need;
      continue;
    } else {
      num = num + (t[i] - ti);
      ti = t[i];
      continue;
    }
  }
  for (i = 1; i <= n; i++) printf("%I64d\n", ans[i]);
  return 0;
}
