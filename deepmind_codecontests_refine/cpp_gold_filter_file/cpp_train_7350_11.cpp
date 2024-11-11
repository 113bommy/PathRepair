#include <bits/stdc++.h>
using namespace std;
const int size1 = 2005;
const int INF = (1 << 30);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k, i;
  cin >> n >> m >> k;
  static int x[size1], y[size1], x1[size1], x2[size1], x3[size1], y1[size1],
      y2[size1], y3[size1], x4[size1], y4[size1];
  for (i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
  }
  int l = -1, r = 1e9;
  while (r - l > 1) {
    int m1 = (l + r) / 2;
    vector<int> v, v1, v2, v3;
    v.push_back(1);
    v.push_back(n);
    v1.push_back(1);
    v1.push_back(m);
    for (i = 1; i <= k; i++) {
      x1[i] = max(x[i] - m1, 1);
      x2[i] = min(x[i] + m1, n);
      y1[i] = max(y[i] - m1, 1);
      y2[i] = min(y[i] + m1, m);
      v.push_back(x1[i]);
      v.push_back(x2[i]);
      v1.push_back(y1[i]);
      v1.push_back(y2[i]);
      v.push_back(max(x[i] - m1 - 1, 1));
      v.push_back(min(x[i] + m1 + 1, n));
      v1.push_back(max(y[i] - m1 - 1, 1));
      v1.push_back(min(y[i] + m1 + 1, m));
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    if (v[0] >= 1 && v[0] <= n) {
      v2.push_back(v[0]);
    }
    if (v1[0] >= 1 && v1[0] <= m) {
      v3.push_back(v1[0]);
    }
    for (i = 1; i < v.size(); i++) {
      if (v[i] != v[i - 1] && v[i] >= 1 && v[i] <= n) {
        v2.push_back(v[i]);
      }
    }
    for (i = 1; i < v1.size(); i++) {
      if (v1[i] != v1[i - 1] && v1[i] >= 1 && v1[i] <= m) {
        v3.push_back(v1[i]);
      }
    }
    int j;
    for (i = 1; i <= k; i++) {
      for (j = 0; j < v2.size(); j++) {
        if (x1[i] == v2[j]) {
          x3[i] = j;
        }
        if (x2[i] == v2[j]) {
          x4[i] = j;
        }
      }
    }
    for (i = 1; i <= k; i++) {
      for (j = 0; j < v3.size(); j++) {
        if (y1[i] == v3[j]) {
          y3[i] = j;
        }
        if (y2[i] == v3[j]) {
          y4[i] = j;
        }
      }
    }
    static int used[size1];
    int maxx = 0, maxy = 0, minx = INF, miny = INF;
    for (i = 0; i < v2.size(); i++) {
      for (j = 0; j < v3.size(); j++) {
        used[j] = 0;
      }
      for (j = 1; j <= k; j++) {
        if (x3[j] <= i && i <= x4[j]) {
          used[y3[j]]++;
          used[y4[j] + 1]--;
        }
      }
      int sum = 0;
      for (j = 0; j < v3.size(); j++) {
        sum += used[j];
        if (sum == 0) {
          minx = min(minx, v2[i]);
          maxx = max(maxx, v2[i]);
        }
      }
    }
    for (i = 0; i < v3.size(); i++) {
      for (j = 0; j < v2.size(); j++) {
        used[j] = 0;
      }
      for (j = 1; j <= k; j++) {
        if (y3[j] <= i && i <= y4[j]) {
          used[x3[j]]++;
          used[x4[j] + 1]--;
        }
      }
      int sum = 0;
      for (j = 0; j < v2.size(); j++) {
        sum += used[j];
        if (sum == 0) {
          miny = min(miny, v3[i]);
          maxy = max(maxy, v3[i]);
        }
      }
    }
    int res = max((maxx - minx + 1) / 2, (maxy - miny + 1) / 2);
    if (res <= m1) {
      r = m1;
    } else {
      l = m1;
    }
  }
  cout << r;
  return 0;
}
