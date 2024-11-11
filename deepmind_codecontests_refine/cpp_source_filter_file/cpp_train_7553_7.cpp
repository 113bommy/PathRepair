#include <bits/stdc++.h>
using namespace std;
const int nmax = 100100;
pair<int, string> p[nmax];
int bonus1[nmax];
int bonus2[nmax];
int bonus[nmax];
int b[nmax];
int n;
struct I1 {
  int ind;
  I1(int iind = -1) : ind(iind) {}
  bool operator<(const I1& other) const {
    int v1 = p[ind].first + bonus2[ind];
    int v2 = p[other.ind].first + bonus2[other.ind];
    if (v1 != v2) {
      return v1 > v2;
    }
    return p[ind].second > p[other.ind].second;
  }
};
struct I2 {
  int ind;
  I2(int iind = -1) : ind(iind) {}
  bool operator<(const I2& other) const {
    int v1 = p[ind].first + bonus2[ind];
    int v2 = p[other.ind].first + bonus2[other.ind];
    if (v1 != v2) {
      return v1 > v2;
    }
    return p[ind].second < p[other.ind].second;
  }
};
struct I {
  int ind;
  I(int iind = -1) : ind(iind) {}
  bool operator<(const I& other) const {
    int v1 = p[ind].first + bonus[ind];
    int v2 = p[other.ind].first + bonus[other.ind];
    if (v1 != v2) {
      return v1 > v2;
    }
    return p[ind].second < p[other.ind].second;
  }
};
I ind[nmax];
char buf[100];
string v;
int indv;
priority_queue<I1> pq1;
priority_queue<I2> pq2;
int findIV() {
  for (int i = 0; i < n; ++i) {
    ind[i].ind = i;
  }
  sort(ind, ind + n);
  for (int i = 0; i < n; ++i) {
    if (ind[i].ind == indv) {
      return i;
    }
  }
  throw -1;
  return -1;
}
int getMin(int m) {
  if (m == 0) {
    return indv;
  }
  memset(bonus, 0, sizeof(bonus));
  for (int i = 0; i < n; ++i) {
    if (i != indv) {
      pq1.push(I1(i));
    }
  }
  if (m == n) {
    bonus1[indv] = b[m - 1];
    --m;
  }
  I iv(indv);
  for (int i = 0; i < m && !pq1.empty();) {
    I t = pq1.top().ind;
    if (iv < t) {
      bonus[t.ind] = b[i];
      if (t < iv) {
        ++i;
      }
    }
    pq1.pop();
  }
  while (!pq2.empty()) {
    pq1.pop();
  }
  return findIV();
}
int getMax(int m) {
  if (m == 0) {
    return indv;
  }
  memset(bonus2, 0, sizeof(bonus2));
  for (int i = 0; i < n; ++i) {
    if (i != indv) {
      pq2.push(I2(i));
    }
  }
  bonus2[indv] = b[0];
  for (int i = 1; i < m; ++i) {
    bonus2[pq2.top().ind] = b[i];
    pq2.pop();
  }
  while (!pq2.empty()) {
    pq2.pop();
  }
  memcpy(bonus, bonus2, sizeof(bonus));
  return findIV();
}
int main() {
  int m;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", buf, &p[i].first);
    p[i].second = buf;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
  }
  sort(b, b + m, greater<int>());
  scanf("%s", buf);
  v = buf;
  for (int i = 0; i < n; ++i) {
    p[i].first = -p[i].first;
  }
  sort(p, p + n);
  indv = -1;
  for (int i = 0; i < n; ++i) {
    if (p[i].second == v) {
      indv = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    p[i].first = -p[i].first;
  }
  printf("%d %d\n", getMax(m) + 1, getMin(m) + 1);
  return 0;
}
