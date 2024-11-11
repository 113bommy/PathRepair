#include <bits/stdc++.h>
using namespace std;
map<long long, int> m, mj;
vector<int> v[20], to[20];
vector<long long> tv[20];
long long sv[20];
vector<int> a[1 << 15], an[1 << 15], av[1 << 15];
int ansn[20], ansv[20];
int main() {
  int n;
  scanf("%d", &n);
  long long s = 0;
  for (int i = 0; i < n; i++) {
    int l, x;
    scanf("%d", &l);
    sv[i] = 0;
    for (int j = 0; j < l; j++) {
      scanf("%d", &x);
      v[i].push_back(x);
      m[x] = i;
      mj[x] = j;
      sv[i] += x;
    }
    to[i] = vector<int>(l, 0);
    s += sv[i];
  }
  if (s % n) {
    puts("No");
    return 0;
  }
  s /= n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      long long t = s - sv[i] + v[i][j];
      tv[i].push_back(t);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int p = i, q = j, b = 0;
      vector<int> tp, tq, tt(n, 0);
      long long t;
      do {
        tt[p] = 1;
        tp.push_back(p);
        tq.push_back(q);
        to[p][q] = tp.size();
        t = tv[p][q];
        if (!m.count(t)) {
          p = -1;
          break;
        } else {
          p = m[t];
          q = mj[t];
        }
      } while (!tt[p] && !to[p][q]);
      if (p != -1 && to[p][q] == 1) {
        int fi = to[p][q] - 1;
        if (t == v[p][q]) {
          for (int k = fi; k < tp.size(); k++) {
            b |= 1 << tp[k];
          }
          a[b].clear();
          an[b].clear();
          av[b].clear();
          for (int k = fi; k < tp.size(); k++) {
            a[b].push_back(tp[k]);
            av[b].push_back(v[tp[k]][tq[k]]);
            an[b].push_back(tp[(k + tp.size() - 1) % tp.size()]);
          }
        }
      }
      for (int k = 0; k < tp.size(); k++) {
        to[tp[k]][tq[k]] = 0;
      }
    }
  }
  for (int i = 1; i < 1 << n; i++) {
    if (a[i].size()) continue;
    for (int j = i; j; j = i & (j - 1)) {
      int k = j ^ i;
      if (!k) continue;
      if (a[j].size() && a[k].size()) {
        for (int l = 0; l < a[j].size(); l++) {
          a[i].push_back(a[j][l]);
          an[i].push_back(an[j][l]);
          av[i].push_back(av[j][l]);
        }
        for (int l = 0; l < a[k].size(); l++) {
          a[i].push_back(a[k][l]);
          an[i].push_back(an[k][l]);
          av[i].push_back(av[k][l]);
        }
        break;
      }
    }
  }
  int M = (1 << n) - 1;
  if (a[M].size()) {
    puts("Yes");
    for (int i = 0; i < n; i++) {
      ansn[a[M][i]] = an[M][i];
      ansv[a[M][i]] = av[M][i];
    }
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", ansv[i], ansn[i] + 1);
    }
  } else {
    puts("No");
  }
  return 0;
}
