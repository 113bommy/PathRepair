#include <bits/stdc++.h>
using namespace std;
int a[100004], r[100004], b[100004];
vector<int> c1, c2;
int check(int x) {
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) return 0;
    x /= 10;
  }
  return 1;
}
int bin(int key, int l, int r) {
  if (r - l <= 1) {
    if (b[l] == key)
      return l;
    else
      return r;
  }
  int m = (l + r) / 2;
  if (key > b[m])
    return bin(key, m + 1, r);
  else
    return bin(key, l, m);
}
void swaping(int p, int q) {
  int sw = a[q];
  a[q] = a[p];
  a[p] = sw;
  c1.push_back(p);
  c2.push_back(q);
}
int main() {
  int i, n, l = -1, k, f;
  while (cin >> n) {
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
      if (l < 0) {
        if (check(a[i])) l = i;
      }
    }
    sort(b + 1, b + n + 1);
    if (l < 0) {
      for (i = 1; i <= n; i++)
        if (a[i] != b[i]) break;
      if (i > n)
        cout << 0 << endl;
      else
        cout << -1 << endl;
      continue;
    }
    for (i = 1; i <= n; i++) {
      k = bin(a[i], 1, n);
      while (r[k]) k++;
      r[k] = i;
      if (i == l) f = k;
    }
    for (i = 1; i <= n; i++) a[r[i]] = i;
    for (i = 1; i <= n; i++) {
      if (a[i] != i && i != f) {
        int t = a[i], l0 = l;
        if (i != l) {
          swaping(i, l);
          r[t] = l;
          l0 = i;
        }
        if (r[i] != l0) {
          swaping(i, r[i]);
          l0 = r[i];
        }
        l = l0;
      }
    }
    cout << c1.size() << endl;
    for (i = 0; i < c1.size(); i++) cout << c1[i] << " " << c2[i] << endl;
  }
  return 0;
}
