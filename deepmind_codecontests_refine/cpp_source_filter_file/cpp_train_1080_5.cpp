#include <bits/stdc++.h>
using namespace std;
int n, m, now = 1;
vector<pair<int, int> > has[322];
long long fun[322], sig[322];
int siz[322];
int x[100005], xx[100005], fa[100005], det[100005], id[100005];
int cmp(int a, int b) { return x[a] < x[b]; }
void setting(int now) {
  siz[now] = has[now].size();
  int tot = 0;
  long long sum = 0;
  sig[now] = fun[now] = 0;
  for (int it = 0; it < has[now].size(); ++it) {
    int he = has[now][it].first;
    fa[has[now][it].second] = now;
    det[has[now][it].second] = tot;
    sig[now] += he;
    fun[now] += 1ll * tot * he - sum;
    sum += he;
    tot++;
  }
}
void print() {
  for (int i = 0; i < now; ++i) {
    for (int j = 0; j < has[i].size(); ++j) {
      printf("%d ", has[i][j].first);
    }
  }
  puts("");
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x[i]);
    id[i] = i;
    xx[i] = x[i];
  }
  sort(xx, xx + n);
  sort(id, id + n, cmp);
  for (int i = 0; i < n; ++i) {
    if (has[now - 1].size() >= 3) {
      now++;
    }
    has[now - 1].push_back(make_pair(x[id[i]], id[i]));
  }
  for (int i = 0; i < now; ++i) {
    siz[i] = has[i].size();
    int tot = 0;
    long long sum = 0;
    for (int it = 0; it < has[i].size(); ++it) {
      int tmp = has[i][it].first;
      fun[i] += 1ll * tot * tmp - sum;
      sig[i] += tmp;
      int to = lower_bound(xx, xx + n, tmp) - xx;
      fa[id[to]] = i;
      det[id[to]] = tot;
      sum += tmp;
      tot++;
    }
  }
  scanf("%d", &m);
  int a, b, c;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1) {
      int k = fa[--b];
      int tmp = has[k][det[b]].first, tmp2 = has[k][det[b]].second;
      has[k][det[b]].first = 1e9 + 1;
      sort(has[k].begin(), has[k].end());
      has[k].pop_back();
      tmp += c;
      int j;
      if (c > 0) {
        for (j = k; j < now; ++j) {
          vector<pair<int, int> >::iterator d =
              lower_bound(has[j].begin(), has[j].end(), make_pair(tmp, -1));
          if (d != has[j].end() || j == now - 1) break;
        }
        has[j].push_back(make_pair(tmp, tmp2));
        for (int jj = k; jj <= j; ++jj) {
          sort(has[jj].begin(), has[jj].end());
          setting(jj);
        }
      } else {
        for (j = k; j >= 0; --j) {
          vector<pair<int, int> >::iterator d =
              lower_bound(has[j].begin(), has[j].end(), make_pair(tmp, -1));
          if (d != has[j].begin() || j == 0) break;
        }
        has[j].push_back(make_pair(tmp, tmp2));
        for (int jj = k; jj >= j; --jj) {
          sort(has[jj].begin(), has[jj].end());
          setting(jj);
        }
      }
    } else {
      int fab = -1, detb;
      for (int i = 0; i < now; ++i) {
        int it = lower_bound(has[i].begin(), has[i].end(), make_pair(b, -1)) -
                 has[i].begin();
        if (it != (int)has[i].size() && has[i][it].first >= b) {
          fab = i;
          detb = it;
          break;
        }
      }
      int fac = -1, detc;
      for (int i = 0; i < now; ++i) {
        int it = upper_bound(has[i].begin(), has[i].end(), make_pair(c, n)) -
                 has[i].begin();
        if (it != 0) {
          if (it == (int)has[i].size() && has[i + 1].size() != 0 &&
              has[i + 1][0].first <= c)
            continue;
          fac = i;
          detc = it - 1;
          break;
        }
      }
      if (fab == -1 || fac == -1 || fab > fac || (fab == fac && detb > detc)) {
        puts("0");
        continue;
      }
      int tot = 0;
      long long sum = 0, ans = 0;
      if (fab == fac) {
        int ever = 0;
        for (int it = 0; it != has[fab].size(); ++it) {
          if (ever >= detb && ever <= detc) {
            ans += 1ll * tot * has[fab][it].first - sum;
            sum += has[fab][it].first;
            tot++;
          }
          ever++;
        }
      } else {
        int ever = 0;
        for (int it = 0; it != has[fab].size(); ++it) {
          if (ever >= detb) {
            ans += 1ll * tot * has[fab][it].first - sum;
            sum += has[fab][it].first;
            tot++;
          }
          ever++;
        }
        for (int j = fab + 1; j < fac; ++j) {
          ans += 1ll * tot * sig[j] - siz[j] * sum + fun[j];
          sum += sig[j];
          tot += siz[j];
        }
        ever = 0;
        for (int it = 0; it != has[fac].size(); ++it) {
          if (ever <= detc) {
            ans += 1ll * tot * has[fac][it].first - sum;
            sum += has[fac][it].first;
            tot++;
          }
          ever++;
        }
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
