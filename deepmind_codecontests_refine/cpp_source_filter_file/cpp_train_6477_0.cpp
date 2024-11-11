#include <bits/stdc++.h>
using namespace std;
const int N = 1234567;
int n;
int a[N];
int c[N];
int d[N];
int f[N];
vector<int> ar;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ar.push_back(a[i]);
  }
  sort(ar.begin(), ar.end());
  ar.erase(unique(ar.begin(), ar.end()), ar.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(ar.begin(), ar.end(), a[i]) - ar.begin();
    c[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    d[c[i]] += 1;
  }
  for (int i = 1; i <= n; i++) {
    d[i] += d[i - 1];
  }
  int ans = 0;
  int u, v;
  for (int i = 1; i * i <= n; i++) {
    long long s = 0;
    for (int j = 1; i * j <= n; j++) {
      if (j <= i) {
        s += 1LL * j * (d[j] - d[j - 1]);
      } else {
        s += 1LL * i * (d[j] - d[j - 1]);
      }
      if (i <= j) {
        if (s + 1LL * (d[n] - d[j]) * i >= i * j) {
          if (ans < i * j) {
            ans = i * j;
            u = i;
            v = j;
          }
        }
      }
    }
  }
  if (v < u) swap(u, v);
  vector<int> bb;
  for (int i = 0; i < n; i++) {
    if (c[i] >= u) {
      for (int j = 0; j < min(u, c[i]); j++) {
        bb.push_back(i);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (c[i] < u) {
      for (int j = 0; j < min(u, c[i]); j++) {
        bb.push_back(i);
      }
    }
  }
  reverse(bb.begin(), bb.end());
  vector<vector<int>> cc(u, vector<int>(v, -1));
  for (int i = 0; i < u * v; i++) {
    int x = i % u;
    int y = (i + i / u) % v;
    cc[x][y] = bb.back();
    bb.pop_back();
  }
  cout << u * v << "\n";
  cout << u << " " << v << "\n";
  for (int i = 0; i < u; i++) {
    for (int j = 0; j < v; j++) {
      cout << ar[cc[i][j]] << " ";
    }
    cout << "\n";
  }
  return 0;
}
