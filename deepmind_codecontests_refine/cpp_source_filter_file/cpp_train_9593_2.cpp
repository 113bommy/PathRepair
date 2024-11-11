#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  int t;
  while (a > 0) t = b % a, b = a, a = t;
  return b;
}
int factor[10000001];
vector<int> primes;
int occ[10000001], occ2[10000001];
int a[100000];
vector<int> fact[100000];
vector<int> ans, ans2, ans3;
int taken[100000];
int getNum(int i, int* occ) {
  int j, k, c = 0;
  for (j = 0; j < (1 << fact[i].size()); j++) {
    int p = 1, b = 0;
    for (k = 0; k < fact[i].size(); k++) {
      if (j & (1 << k)) p *= fact[i][k], b++;
    }
    if (b & 1)
      c -= occ[p];
    else
      c += occ[p];
  }
  return c;
}
vector<int> order;
int main() {
  int i;
  int n, kk;
  scanf("%d %d", &n, &kk);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  int j, k;
  memset(factor, -1, sizeof(factor));
  for (i = 2; i < 10000000; i++) {
    if (factor[i] == -1) {
      for (j = i; j < 10000000; j += i) factor[j] = i;
      primes.push_back(i);
    }
  }
  for (i = 0; i < n; i++) {
    int t = a[i];
    while (t > 1) {
      int f = factor[t];
      while ((t % f) == 0) t /= f;
      fact[i].push_back(f);
    }
    for (j = 0; j < (1 << fact[i].size()); j++) {
      int p = 1;
      for (k = 0; k < fact[i].size(); k++) {
        if (j & (1 << k)) p *= fact[i][k];
      }
      occ[p]++;
    }
  }
  for (i = 0; i < n; i++) {
    if (getNum(i, occ2) == 0) {
      ans2.push_back(i);
      for (j = 0; j < (1 << fact[i].size()); j++) {
        int p = 1;
        for (k = 0; k < fact[i].size(); k++) {
          if (j & (1 << k)) p *= fact[i][k];
        }
        occ2[p]++;
      }
    }
    if (ans2.size() == kk) {
      for (j = 0; j < kk; j++) printf("%d ", ans2[j] + 1);
      printf("\n");
      return 0;
    }
    if (ans.empty() && (getNum(i, occ) >= 2)) {
      ans.push_back(i), taken[i] = 1;
      for (j = 0; j < n; j++) {
        if ((i != j) && (ans.size() < 3) && (gcd(a[i], a[j]) == 1))
          ans.push_back(j), taken[j] = 1;
      }
    }
  }
  int l;
  ans2.clear(), memset(occ2, 0, sizeof(occ2));
  for (i = 0; i < n; i++) {
    if (taken[i]) {
      for (j = 0; j < (1 << fact[i].size()); j++) {
        int p = 1;
        for (k = 0; k < fact[i].size(); k++) {
          if (j & (1 << k)) p *= fact[i][k];
        }
        occ[p]--;
      }
    } else
      order.push_back(i);
  }
  random_shuffle(order.begin(), order.end());
  for (i = 0; i < order.size(); i++) {
    int u = order[i];
    if (getNum(u, occ2) == 0) {
      if (getNum(u, occ) == 0)
        ans3.push_back(u);
      else
        ans2.push_back(u);
      for (j = 0; j < (1 << fact[u].size()); j++) {
        int p = 1;
        for (k = 0; k < fact[u].size(); k++) {
          if (j & (1 << k)) p *= fact[u][k];
        }
        occ2[p]++;
      }
    } else {
      ans.push_back(u);
      int f = 0;
      vector<int> temp;
      for (j = 0; j < ans2.size(); j++) {
        if (((ans.size() <= kk) || !f) && (gcd(a[ans2[j]], a[u]) == 1)) {
          ans.push_back(ans2[j]), f = 1;
          int v = ans2[j];
          for (k = 0; k < (1 << fact[v].size()); k++) {
            int p = 1;
            for (l = 0; l < fact[v].size(); l++) {
              if (k & (1 << l)) p *= fact[v][l];
            }
            occ2[p]--;
          }
        } else
          temp.push_back(ans2[j]);
      }
      ans2 = temp;
    }
    if (ans.size() >= kk) {
      for (j = 0; j < ans.size(); j++) {
        if ((j == 2) && (ans.size() > k)) continue;
        printf("%d ", ans[j] + 1);
      }
      printf("\n");
      return 0;
    }
    if (ans2.size() + ans3.size() == kk) {
      for (j = 0; j < ans2.size(); j++) printf("%d ", ans2[j] + 1);
      for (j = 0; j < ans3.size(); j++) printf("%d ", ans3[j] + 1);
      printf("\n");
      return 0;
    }
    for (j = 0; j < (1 << fact[u].size()); j++) {
      int p = 1;
      for (k = 0; k < fact[u].size(); k++) {
        if (j & (1 << k)) p *= fact[u][k];
      }
      occ[p]--;
    }
  }
  return 0;
}
