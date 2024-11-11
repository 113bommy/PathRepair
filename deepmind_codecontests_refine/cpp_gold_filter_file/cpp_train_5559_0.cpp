#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
int k = 0;
int vi[301], e, v, n, a[301], b[301], te[301], num, s1[160001], s2[160001],
    w[160001], path[301], nu, q, q2, v2[301], cur[301], tar;
struct node {
  int dir;
  node* next;
};
struct data {
  int w, u;
};
bool operator<(data x, data y) {
  if (x.w > y.w) {
    return true;
  }
  return false;
}
node *h[301], *ba[301];
void insert(int s, int t) {
  node* temp = new node;
  temp->dir = t;
  temp->next = NULL;
  ba[s]->next = temp;
  ba[s] = temp;
}
void visit(int s) {
  vi[s] = 1;
  te[++num] = s;
  node* temp = h[s];
  while (temp->next != NULL) {
    temp = temp->next;
    if (!vi[temp->dir]) {
      visit(temp->dir);
    }
  }
}
void transfer(int s, int st, int wi) {
  if (st == nu) {
    s1[++k] = s;
    s2[k] = tar;
    w[k] = wi;
    cur[tar] += wi;
    cur[s] -= wi;
  } else {
    int t2 = path[st + 1];
    int v2 = min(wi, v - cur[t2]);
    if (v2 != 0) {
      s1[++k] = s;
      s2[k] = t2;
      w[k] = v2;
      cur[s] -= v2;
      cur[t2] += v2;
    }
    transfer(t2, st + 1, wi);
    if (v2 != wi) {
      s1[++k] = s;
      s2[k] = t2;
      w[k] = wi - v2;
      cur[s] -= (wi - v2);
      cur[t2] += (wi - v2);
    }
  }
}
bool findpath(int s) {
  v2[s] = 1;
  if (s == q2) {
    return true;
  }
  node* temp = h[s];
  while (temp->next != NULL) {
    temp = temp->next;
    if (!v2[temp->dir]) {
      if (findpath(temp->dir)) {
        path[++nu] = temp->dir;
        return true;
      }
    }
  }
  return false;
}
int grid[301][301];
int main() {
  cin >> n >> v >> e;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      grid[i][j] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    cur[i] = a[i];
  }
  for (long long i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (long long i = 1; i <= n; i++) {
    h[i] = new node;
    ba[i] = h[i];
    h[i]->next = NULL;
  }
  for (long long i = 1; i <= e; i++) {
    int s, t;
    cin >> s >> t;
    if (!grid[s][t]) {
      insert(s, t);
      insert(t, s);
      grid[s][t] = 1;
    }
  }
  for (long long i = 1; i <= n; i++) {
    vi[i] = 0;
  }
  for (long long i = 1; i <= n; i++) {
    if (!vi[i]) {
      num = 0;
      long long asum = 0, bsum = 0;
      visit(i);
      for (long long j = 1; j <= num; j++) {
        asum += a[te[j]];
        bsum += b[te[j]];
      }
      if (asum != bsum) {
        cout << "NO" << endl;
        return 0;
      }
      data tmp[num + 1];
      for (long long i = 1; i <= num; i++) {
        tmp[i].w = b[te[i]] - a[te[i]];
        tmp[i].u = te[i];
      }
      sort(tmp + 1, tmp + num + 1);
      q = num;
      for (long long i = 1; i <= num; i++) {
        while (tmp[i].w != 0) {
          while (tmp[q].w == 0) {
            q--;
          }
          q2 = tmp[q].u;
          int take = min(-1 * tmp[q].w, tmp[i].w);
          nu = 0;
          for (long long j = 1; j <= n; j++) {
            v2[j] = 0;
          }
          findpath(tmp[i].u);
          tar = tmp[i].u;
          transfer(tmp[q].u, 1, take);
          tmp[q].w += take;
          tmp[i].w -= take;
        }
      }
    }
  }
  cout << k << endl;
  for (long long i = 1; i <= k; i++) {
    cout << s1[i] << " " << s2[i] << " " << w[i] << endl;
  }
  return 0;
}
